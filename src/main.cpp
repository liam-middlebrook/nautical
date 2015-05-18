#include "scripts/loaders.h"
#include "script.h"
#include "engine.h"
#include <iostream>

#define UNUSED (void)

int main(int argc, char** argv)
{
    nautical::Engine engine;
#ifdef NAUTICAL_BIND_PYTHON
    engine.addScriptLoader(new nautical::script::PythonScriptLoader);
#endif

    std::string dir = ".";
    if(argc == 2) {
        dir = argv[1];
    } else if(argc != 1) {
        std::cerr << "Please specify only one directory\n";
        return 1;
    }
    engine.run(dir);
    return 0;
}
// vim: expandtab
