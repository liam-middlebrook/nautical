#include <cmath>

namespace nautical
{
    namespace math
    {
        template <typename T>
        class Vector2
        {
            public:
                    union
                    {
                            struct { T x; T y;};
                            T components[2];
                    };
                    Vector2(T x, T y) : x(x), y(y) {};
                    Vector2(T* data)
                    {
                            memcpy(components, data, sizeof(T) * 2);
                    };

                    inline T length()
                    {
                        return sqrt(x*x + y*y);
                    }

                    inline T direction()
                    {
                        return atan2(y, x);
                    }
        };
    }
}
