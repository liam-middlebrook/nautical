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
            T x, y;

            Vector2() : x(0), y(0)
            {
            }

            Vector2(T x, T y) : x(x), y(y)
            {
            }

            Vector2(const T* data)
            {
                memcpy(&x, data, sizeof(T) * 2);
            }

            inline T& operator[](int b)
            {
                return (&x)[b];
            }

            inline const T& operator[](int b) const
            {
                return (&x)[b];
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

            inline Vector2 operator+(const Vector2& b) const
            {
                return (Vector2(*this) += b);
            }

            inline Vector2& operator+=(const Vector2& rhs)
            {
                this->x += rhs.x;
                this->y += rhs.y;
                return *this;
            }

            inline Vector2 operator-() const
            {
                Vector2 out;
                out.x = -x;
                out.y = -y;
                return out;
            }

            inline Vector2 operator-(const Vector2& b) const
            {
                return (Vector2(*this) -= b);
            }

            inline Vector2& operator-=(const Vector2& rhs)
            {
                this->x -= rhs.x;
                this->y -= rhs.y;
                return *this;
            }

            inline Vector2 operator*(const Vector2& b) const
            {
                return (Vector2(*this) *= b);
            }

            inline Vector2& operator*=(const Vector2& rhs)
            {
                this->x *= rhs.x;
                this->y *= rhs.y;
                return *this;
            }

            inline Vector2 operator/(const Vector2& b) const
            {
                return (Vector2(*this) /= b);
            }

            inline Vector2& operator/=(const Vector2& rhs)
            {
                this->x /= rhs.x;
                this->y /= rhs.y;
                return *this;
            }

            inline Vector2 operator*(const T& b) const
            {
                return (Vector2(*this) *= b);
            }

            inline Vector2& operator*=(const T& rhs)
            {
                this->x *= rhs;
                this->y *= rhs;
                return *this;
            }

            inline Vector2 operator/(const T& b) const
            {
                return (Vector2(*this) /= b);
            }

            inline Vector2& operator/=(const T& rhs)
            {
                this->x /= rhs;
                this->y /= rhs;
                return *this;
            }

            inline Vector2& operator=(const Vector2& rhs)
            {
                this->x = rhs.x;
                this->y = rhs.y;
                return *this;
            }

            inline bool operator==(const Vector2& rhs) const
            {
                return this->x == rhs.x && this->y == rhs.y;
            }

            inline bool operator!=(const Vector2& rhs) const
            {
                return !(*this == rhs);
            }

            inline operator T*()
            {
                return &x;
            }

            inline Vector2 normalized() const
            {
                if (lengthSquared() == 0)
                {
                    return Vector2::zero;
                }
                return *this / length();
            }

            inline void normalize()
            {
                Vector2 temp = normalized();
                this->x = temp.x;
                this->y = temp.y;
            }

            inline T dot(const Vector2& b)
            {
                return x * b.x + y * b.y;
            }

            static const Vector2 zero;
            static const Vector2 one;
            static const Vector2 right;
            static const Vector2 up;
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
