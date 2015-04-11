#pragma once
#ifdef NAUTICAL_BIND_PYTHON

#include <Python.h>
#include "script.h"
#include "scriptloader.h"

namespace nautical
{
    namespace script
    {
        class PythonScript : public Script
        {
        public:
            PythonScript(PyObject* obj);
            ~PythonScript();

            void init();
            void update();
            void lateUpdate();

        private:
            PyObject* _obj;
        };
    }
}

#endif
