#include "engine.h"

#define UNUSED (void)

int main(int argc, char** argv)
{
    UNUSED argc;
    UNUSED argv;

    nautical::Engine *engine = new nautical::Engine();

    engine->run();

    delete engine;

    return 0;
}
