#pragma once
#ifdef NAUTICAL_BIND_PYTHON

#include <Python.h>
#include "scriptloader.h"

namespace nautical
{
    namespace script
    {
        class PythonScriptLoader : public ScriptLoader
        {
        public:
            PythonScriptLoader();
            ~PythonScriptLoader();
            virtual bool load(std::string);
            virtual Script* script(std::string);

        private:
            PyObject* context;
        };
    }
}

#endif
