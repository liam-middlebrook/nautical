#pragma once

#include <string>
#include <vector>

namespace nautical
{

    namespace script
    {
        class Script;
        class ScriptFactory;

        struct ScriptLoader
        {
            virtual bool load(std::string) = 0;
            virtual Script *script(std::string) = 0;
            virtual ~ScriptLoader()
            {
            }
        };

        class ScriptFactory
        {
        public:
            void addLoader(ScriptLoader *loader)
            {
                loaders.push_back(loader);
            }

            Script *script(std::string name)
            {
                for (auto &loader : loaders)
                {
                    if (auto sc = loader->script(name))
                    {
                        return sc;
                    }
                }
                return nullptr;
            }

            void load(std::string name)
            {
                for (auto &loader : loaders)
                {
                    if (loader->load(name))
                    {
                        return;
                    }
                }
            }

            ~ScriptFactory()
            {
                for (auto &loader : loaders)
                {
                    delete loader;
                }
            }

        private:
            std::vector<ScriptLoader *> loaders;
        };
    }
}
