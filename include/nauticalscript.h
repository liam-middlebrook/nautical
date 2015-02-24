#pragma once

#include "transform.h"
#include <unordered_map>

namespace nautical
{
    class NauticalScript
    {
    public:
        NauticalScript();

        virtual ~NauticalScript();

        virtual void update() = 0;

        virtual void lateUpdate() = 0;
    };
}
