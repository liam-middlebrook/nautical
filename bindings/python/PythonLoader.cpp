#include <Python.h>
#include <string>
#include "scripts/PythonLoader.h"

using std::string;

namespace nautical
{
    PythonScriptLoader::PythonScriptLoader()
    {
        Py_Initialize();
        // PyObject *main = PyImport_AddModule("__main__");
    }
    PythonScriptLoader::~PythonScriptLoader()
    {
        Py_Finalize();
    }
    bool PythonScriptLoader::load(string fname)
    {
        if (fname.substr(fname.length() - 3, fname.length()) != ".py")
        {
            return false;
        }
    }
    Script *PythonScriptLoader::script(string filename)
    {
        return nullptr;
    }
}
