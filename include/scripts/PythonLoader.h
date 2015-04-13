#pragma once
#ifdef NAUTICAL_BIND_PYTHON

#include <Python.h>
#include "scriptloader.h"

namespace nautical
{
    class GameObject;
    namespace script
    {
        class PythonScriptLoader : public ScriptLoader
        {
        public:
            PythonScriptLoader();
            ~PythonScriptLoader();
            virtual bool load(std::string);
            virtual Script* script(std::string, GameObject* gameObject);

        private:
            PyObject* context;
        };
    }
}

#endif
