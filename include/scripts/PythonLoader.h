#pragma once
#ifdef NAUTICAL_BIND_PYTHON

#include "scriptloader.h"

namespace nautical
{
    class PythonScriptLoader : public ScriptLoader
    {
    public:
        PythonScriptLoader();
        ~PythonScriptLoader();
        virtual bool load(std::string);
        virtual Script* script(std::string);
    };
}

#endif
