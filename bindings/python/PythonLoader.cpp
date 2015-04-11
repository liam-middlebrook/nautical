#include <Python.h>
#include "swigruntime.py.h"
#include "scripts/PythonLoader.h"
#include "scripts/pythonscript.h"
#include <string>
#include <algorithm>

using std::string;
using nautical::script::Script;
using nautical::script::PythonScript;

namespace
{
    Script *pythonToScript(PyObject *obj)
    {
        PythonScript* script = new PythonScript(obj);

        printf("made a script\n");

        return script;
    }
    void addPythonModulePath(string p)
    {
        static char pthc[5] = "path";
        PyObject *sys_path = PySys_GetObject(pthc);
        if (sys_path == NULL)
            return;
        PyObject *path = PyString_FromString(p.c_str());
        if (path != NULL)
        {
            PyList_Append(sys_path, path);
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
}
namespace nautical
{
    namespace script
    {
        PythonScriptLoader::PythonScriptLoader()
        {
            Py_Initialize();
            context = PyImport_AddModule("__nautical_context__");
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
            auto pos = fname.find_last_of("\\/");
            addPythonModulePath(fname.substr(0, pos));
            ++pos;
            string modn = fname.substr(pos, fname.find_last_of('.') - pos);
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
        Script *PythonScriptLoader::script(string funcname)
        {
            auto fs = PyString_FromString(funcname.c_str());
            PyObject *func = PyObject_GetAttr(context, fs);
            printf("Is it a type? %d\n", PyType_Check(func));
            PyObject *sc = PyObject_CallFunctionObjArgs(func, nullptr);
            Script *ret = pythonToScript(sc);
            Py_DECREF(fs);
            return ret;
        }
    }
}
