#include "scripts/loaders.h"
#include "script.h"
#include "engine.h"

#define UNUSED (void)

int main(int argc, char** argv)
{
    UNUSED argc;
    UNUSED argv;

    nautical::Engine engine = nautical::Engine();
#ifdef NAUTICAL_BIND_PYTHON
	engine.addScriptLoader(new nautical::script::PythonScriptLoader);
#endif

    engine.run();
    return 0;
}
