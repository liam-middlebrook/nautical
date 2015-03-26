#include "engine.h"

#define UNUSED (void)

int main(int argc, char** argv)
{
    UNUSED argc;
    UNUSED argv;

    nautical::Engine engine = nautical::Engine();

    engine.run();

    return 0;
}
