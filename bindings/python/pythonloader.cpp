#include <Python.h>
#include "gameobject.h"
#include "swigruntime.py.h"
#include "scripts/pythonloader.h"
#include "script.h"
#include <string>
#include <algorithm>
using std::string;
using nautical::GameObject;
using nautical::script::Script;

namespace
{
    void addPythonModulePath(string p)
    {
        static char pthc[5] = "path";
        PyObject *sys_path = PySys_GetObject(pthc);
        if (sys_path == NULL)
            return;
        PyObject *path = PyString_FromString(p.c_str());
        if (path != NULL)
        {
            if(!PySequence_Contains(sys_path, path)) {
                PyList_Append(sys_path, path);
            }
            Py_DECREF(path);
        }
    }

    struct EndsWith
    {
        EndsWith(string str) : str(str)
        {
        }
        bool operator()(string prefix)
        {
            return (str.substr(str.length() - prefix.length()) != prefix);
        }

    private:
        string str;
    };

    class PythonScript : public Script
    {
    public:
        PythonScript(PyObject *obj, GameObject* gameObject) : _obj{obj}
        {
            auto type_info = SWIG_TypeQuery("nautical::GameObject *");
            auto pyObject = SWIG_NewPointerObj(gameObject, type_info, 0);
            PyObject_SetAttrString(obj, "gameobject", pyObject);
        }
        ~PythonScript()
        {
            Py_DECREF(_obj);
        }
        void init()
        {
            static char func[] = "init";
            call(func);
        }
        void update()
        {
            static char func[] = "update";
            call(func);
        }
        void lateUpdate()
        {
            static char func[] = "lateUpdate";
            call(func);
        }

    private:
        void call(char *name)
        {
            PyObject_CallMethod(_obj, name, nullptr);
        }
        PyObject *_obj;
    };
}

namespace nautical
{
    namespace script
    {
        PythonScriptLoader::PythonScriptLoader()
        {
            Py_Initialize();
            context = PyImport_AddModule("__nautical_context__");
            addPythonModulePath(get_exe_location() + "bindings/python");
        }
        PythonScriptLoader::~PythonScriptLoader()
        {
            Py_Finalize();
        }
        bool PythonScriptLoader::load(string fname)
        {
            static std::vector<string> sfs = {".py", ".pyc", ".pyo"};
            if (std::none_of(begin(sfs), end(sfs), ::EndsWith(fname)))
            {
                return false;
            }
            string modn = fname;
            if(auto pos = fname.find_last_of("\\/")) {
                addPythonModulePath(fname.substr(0, pos));
                ++pos;
                modn = fname.substr(pos, fname.find_last_of('.') - pos);
            } else {
                addPythonModulePath(".");
            }
            auto mod = PyImport_ImportModule(modn.c_str());
            auto modc = PyModule_GetDict(mod);
            auto itr = PyObject_GetIter(modc);
            while (auto funcname = PyIter_Next(itr))
            {
                if (!PyObject_HasAttr(context, funcname))
                {
                    auto func = PyObject_GetAttr(mod, funcname);
                    PyObject_SetAttr(context, funcname, func);
                    Py_DECREF(func);
                }
                Py_DECREF(funcname);
            }
            Py_DECREF(itr);
            return true;
        }
        Script *PythonScriptLoader::script(string funcname, nautical::GameObject* gameObject)
        {
            auto fs = PyString_FromString(funcname.c_str());
            PyObject *func = PyObject_GetAttr(context, fs);
            PyObject *sc = PyObject_CallFunctionObjArgs(func, nullptr);
            Script *ret = new PythonScript(sc, gameObject);
            Py_DECREF(fs);
            return ret;
        }
    }
}
// vim: expandtab
