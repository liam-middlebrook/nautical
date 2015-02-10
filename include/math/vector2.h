#pragma once

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
            struct
            {
                T x;
                T y;
            };
            T components[2];
        };

        Vector2() : x(0), y(0)
        {
        }
        Vector2(T x, T y) : x(x), y(y)
        {
        }

        Vector2(T* data)
        {
            memcpy(components, data, sizeof(T) * 2);
        }

        inline T lengthSquared() const
        {
            return x * x + y * y;
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

        inline Vector2<T>& operator+=(const Vector2<T>& rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            return *this;
        }

        inline Vector2<T> operator-() const
        {
            Vector2<T> out;
            out.x = -x;
            out.y = -y;
            return out;
        }

        inline Vector2<T> operator-(const Vector2<T>& b) const
        {
            Vector2<T> out;
            out.x = x - b.x;
            out.y = y - b.y;
            return out;
        }

        inline Vector2<T>& operator-=(const Vector2<T>& rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            return *this;
        }

        inline Vector2<T> operator*(const Vector2<T>& b) const
        {
            Vector2<T> out;
            out.x = x * b.x;
            out.y = y * b.y;
            return out;
        }

        inline Vector2<T>& operator*=(const Vector2<T>& rhs)
        {
            this->x *= rhs.x;
            this->y *= rhs.y;
            return *this;
        }

        inline Vector2<T> operator/(const Vector2<T>& b) const
        {
            Vector2<T> out;
            out.x = x / b.x;
            out.y = y / b.y;
            return out;
        }

        inline Vector2<T>& operator/=(const Vector2<T>& rhs)
        {
            this->x /= rhs.x;
            this->y /= rhs.y;
            return *this;
        }

        inline Vector2<T> operator*(const T& b) const
        {
            Vector2<T> out;
            out.x = x * b;
            out.y = y * b;
            return out;
        }

        inline Vector2<T>& operator*=(const T& rhs)
        {
            this->x *= rhs;
            this->y *= rhs;
            return *this;
        }

        inline Vector2<T> operator/(const T& b) const
        {
            Vector2<T> out;
            out.x = x / b;
            out.y = y / b;
            return out;
        }

        inline Vector2<T>& operator/=(const T& rhs)
        {
            this->x /= rhs;
            this->y /= rhs;
            return *this;
        }

        inline Vector2<T>& operator=(const Vector2<T>& rhs)
        {
            this->x = rhs.x;
            this->y = rhs.y;
            return *this;
        }

        inline bool operator==(const Vector2<T>& rhs) const
        {
            return this->x == rhs.x && this->y == rhs.y;
        }

        inline bool operator!=(const Vector2<T>& rhs) const
        {
            return !(*this == rhs);
        }

        inline T operator[](const int& b)
        {
            return components[b];
        }

        inline operator T*()
        {
            return &x;
        }

        inline Vector2<T> normalized()
        {
            if (lengthSquared() == 0)
            {
                return Vector2<T>::zero;
            }
            return *this / length();
        }

        inline void normalize()
        {
            Vector2<T> temp = normalized();
            this->x = temp.x;
            this->y = temp.y;
        }

        inline T dot(Vector2<T>& b)
        {
            return x * b.x + y * b.y;
        }

        const static Vector2<T> zero;
        const static Vector2<T> one;
        const static Vector2<T> right;
        const static Vector2<T> up;
    };

    template <typename T>
    const Vector2<T> Vector2<T>::zero = Vector2<T>(0, 0);

    template <typename T>
    const Vector2<T> Vector2<T>::one = Vector2<T>(1, 1);

    template <typename T>
    const Vector2<T> Vector2<T>::right = Vector2<T>(1, 0);

    template <typename T>
    const Vector2<T> Vector2<T>::up = Vector2<T>(0, 1);
}
}
