#pragma once

#include "math/vector3.h"

namespace nautical
{
    namespace math
    {
        template <typename T>
        class Vector4
        {
        public:
            T x, y, z, w;

            Vector4() : x(0), y(0), z(0), w(0)
            {
            }

            Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w)
            {
            }

            Vector4(const Vector2<T>& rval) : Vector4(rval.x, rval.y, 0, 0)
            {
            }

            Vector4(const Vector3<T>& rval) : Vector4(rval.x, rval.y, rval.z, 0)
            {
            }

            Vector4(const T* data)
            {
                memcpy(&x, data, sizeof(T) * 4);
            }

            inline T& operator[](int b)
            {
                return (&x)[b];
            }

            inline const T& operator[](const int& b) const
            {
                return (&x)[b];
            }

            inline T lengthSquared() const
            {
                return x * x + y * y + z * z + w * w;
            }

            inline T length() const
            {
                return sqrt(lengthSquared());
            }

            inline Vector4 operator+(const Vector4& b) const
            {
                return (Vector4(*this) += b);
            }

            inline Vector4& operator+=(const Vector4& rhs)
            {
                this->x += rhs.x;
                this->y += rhs.y;
                this->z += rhs.z;
                this->w += rhs.w;
                return *this;
            }

            inline Vector4 operator-() const
            {
                Vector4 out;
                out.x = -x;
                out.y = -y;
                out.z = -z;
                out.w = -w;
                return out;
            }

            inline Vector4 operator-(const Vector4& b) const
            {
                return (Vector4(*this) -= b);
            }

            inline Vector4& operator-=(const Vector4& rhs)
            {
                this->x -= rhs.x;
                this->y -= rhs.y;
                this->z -= rhs.z;
                this->w -= rhs.w;
                return *this;
            }

            inline Vector4 operator*(const Vector4& b) const
            {
                return (Vector4(*this) *= b);
            }

            inline Vector4& operator*=(const Vector4& rhs)
            {
                this->x *= rhs.x;
                this->y *= rhs.y;
                this->z *= rhs.z;
                this->w *= rhs.w;
                return *this;
            }

            inline Vector4 operator/(const Vector4& b) const
            {
                return (Vector4(*this) /= b);
            }

            inline Vector4& operator/=(const Vector4& rhs)
            {
                this->x /= rhs.x;
                this->y /= rhs.y;
                this->z /= rhs.z;
                this->w /= rhs.w;
                return *this;
            }

            inline Vector4 operator*(const T& b) const
            {
                return (Vector4(*this) *= b);
            }

            inline Vector4& operator*=(const T& rhs)
            {
                this->x *= rhs;
                this->y *= rhs;
                this->z *= rhs;
                this->w *= rhs;
                return *this;
            }

            inline Vector4 operator/(const T& b) const
            {
                return (Vector4(*this) /= b);
            }

            inline Vector4& operator/=(const T& rhs)
            {
                this->x /= rhs;
                this->y /= rhs;
                this->z /= rhs;
                this->w /= rhs;
                return *this;
            }

            inline Vector4& operator=(const Vector4& rhs)
            {
                this->x = rhs.x;
                this->y = rhs.y;
                this->z = rhs.z;
                this->w = rhs.w;
                return *this;
            }

            inline bool operator==(const Vector4& rhs) const
            {
                return this->x == rhs.x && this->y == rhs.y &&
                       this->z == rhs.z && this->w == rhs.w;
            }

            inline bool operator!=(const Vector4& rhs) const
            {
                return !(*this == rhs);
            }

            inline operator T*()
            {
                return &x;
            }

            inline Vector4 normalized() const
            {
                if (lengthSquared() == 0)
                {
                    return Vector4::zero;
                }
                return *this / length();
            }

            inline void normalize()
            {
                Vector4 temp = normalized();
                this->x = temp.x;
                this->y = temp.y;
                this->z = temp.z;
                this->w = temp.w;
            }

            inline T dot(const Vector4& b)
            {
                return x * b.x + y * b.y + z * b.z + w * b.w;
            }

            const static Vector4 zero;
            const static Vector4 one;
            const static Vector4 right;
            const static Vector4 up;
            const static Vector4 forward;
        };

        template <typename T>
        const Vector4<T> Vector4<T>::zero = Vector4<T>(0, 0, 0, 0);

        template <typename T>
        const Vector4<T> Vector4<T>::one = Vector4<T>(1, 1, 1, 1);

        template <typename T>
        const Vector4<T> Vector4<T>::right = Vector4<T>(1, 0, 0, 0);

        template <typename T>
        const Vector4<T> Vector4<T>::up = Vector4<T>(0, 1, 0, 0);

        template <typename T>
        const Vector4<T> Vector4<T>::forward = Vector4<T>(0, 0, 1, 0);
    }
}
