#include "scripts/Loaders.h"
#include "script.h"
#include "engine.h"

#define UNUSED (void)

using namespace nautical::script;

int main(int argc, char** argv)
{
    UNUSED argc;
    UNUSED argv;

    nautical::Engine engine = nautical::Engine();

    ScriptFactory fac;
#ifdef NAUTICAL_BIND_PYTHON
    fac.addLoader(new PythonScriptLoader);
    fac.load("bindings/python/testing.py");
    printf("About to instantiate the script\n");
    auto s = fac.script("MyScript", engine.world);
    s->init();
    for (int i = 0; i < 5; ++i)
    {
        s->update();
        s->lateUpdate();
    }
#endif
    /*
     *
     *    engine.run();
     */

    return 0;
}
