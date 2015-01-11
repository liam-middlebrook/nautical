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
                    Vector2() : x(0), y(0) {};
                    Vector2(T x, T y) : x(x), y(y) {};
                    Vector2(T* data)
                    {
                            memcpy(components, data, sizeof(T) * 2);
                    };

                    inline T lengthSquared() const
                    {
                        return x*x + y*y;
                    }

                    inline T length() const
                    {
                        return sqrt(lengthSquared());
                    }

                    inline T direction() const
                    {
                        return atan2(y, x);
                    }

                    inline Vector2<T> operator+(const Vector2<T>& b) const
                    {
                        Vector2<T> out;
                        out.x = x + b.x;
                        out.y = y + b.y;
                        return out;
                    }

                    inline Vector2<T>& operator+=(const Vector2<T> rhs)
                    {
                        return *this + rhs;
                    }

                    inline Vector2<T> operator-(const Vector2<T>& b) const
                    {
                        Vector2<T> out;
                        out.x = x - b.x;
                        out.y = y - b.y;
                        return out;
                    }

                    inline Vector2<T>& operator-=(const Vector2<T> rhs)
                    {
                        return *this - rhs;
                    }

                    inline Vector2<T> operator*(const Vector2<T>& b) const
                    {
                        Vector2<T> out;
                        out.x = x * b.x;
                        out.y = y * b.y;
                        return out;
                    }

                    inline Vector2<T>& operator*=(const Vector2<T> rhs)
                    {
                        return *this * rhs;
                    }

                    inline Vector2<T> operator/(const Vector2<T>& b) const
                    {
                        Vector2<T> out;
                        out.x = x / b.x;
                        out.y = y / b.y;
                        return out;
                    }

                    inline Vector2<T>& operator/-(const Vector2<T> rhs)
                    {
                        return *this / rhs;
                    }
        };
    }
}
