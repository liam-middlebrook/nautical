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
    PyObject_CallMethod(_obj, "init", nullptr);
}

void PythonScript::update()
{
    PyObject_CallMethod(_obj, "update", nullptr);
}

void PythonScript::lateUpdate()
{
    PyObject_CallMethod(_obj, "lateUpdate", nullptr);
}
