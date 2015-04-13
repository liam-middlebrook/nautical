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

    engine.run();
    return 0;
}
