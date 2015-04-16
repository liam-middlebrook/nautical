#pragma once

namespace nautical
{
    class Engine;
    namespace script
    {
        class Script
        {
        public:
            virtual ~Script()
            {
            }

            // Initialization Logic for Script
            virtual void init() = 0;

            // Update Logic for Script
            virtual void update() = 0;

            // LateUpdate Logic for Script
            virtual void lateUpdate() = 0;

            nautical::Engine* engine;
        };
    }
}
