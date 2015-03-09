#pragma once

namespace nautical
{
    class NauticalScript
    {
    public:
        NauticalScript();

        virtual ~NauticalScript();

        // Initialization Logic for Script
        virtual void init() = 0;

        // Update Logic for Script
        virtual void update() = 0;

        // LateUpdate Logic for Script
        virtual void lateUpdate() = 0;
    };
}
