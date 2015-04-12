#include <Python.h>
#include "scripts/pythonscript.h"
#include "swigruntime.py.h"
#include "engine.h"
using namespace nautical;
using namespace nautical::script;

PythonScript::PythonScript(PyObject* obj) : _obj{obj}
{
}

PythonScript::~PythonScript()
{
}

void PythonScript::init()
{
    static char func[] = "init";
    PyObject_CallMethod(_obj, func, nullptr);
}

void PythonScript::update()
{
    static char func[] = "update";
    PyObject_CallMethod(_obj, func, nullptr);
}

void PythonScript::lateUpdate()
{
    static char func[] = "lateUpdate";
    PyObject_CallMethod(_obj, func, nullptr);
}
