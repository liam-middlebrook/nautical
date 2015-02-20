#pragma once

#include <cmath>

namespace nautical
{
    namespace math
    {
        template <typename T>
        class Vector3
        {
        public:
            T x, y, z;

            Vector3() : x(0), y(0), z(0)
            {
            }

            Vector3(T x, T y, T z) : x(x), y(y), z(z)
            {
            }

            Vector3(const T* data)
            {
                memcpy(&x, data, sizeof(T) * 3);
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
                return x * x + y * y + z * z;
            }

            inline T length() const
            {
                return sqrt(lengthSquared());
            }

            inline Vector3 operator+(const Vector3& b) const
            {
                return (Vector3(*this) += b);
            }

            inline Vector3& operator+=(const Vector3& rhs)
            {
                this->x += rhs.x;
                this->y += rhs.y;
                this->z += rhs.z;
                return *this;
            }

            inline Vector3 operator-() const
            {
                Vector3 out;
                out.x = -x;
                out.y = -y;
                out.z = -z;
                return out;
            }

            inline Vector3 operator-(const Vector3& b) const
            {
                return (Vector3(*this) -= b);
            }

            inline Vector3& operator-=(const Vector3& rhs)
            {
                this->x -= rhs.x;
                this->y -= rhs.y;
                this->z -= rhs.z;
                return *this;
            }

            inline Vector3 operator*(const Vector3& b) const
            {
                return (Vector3(*this) *= b);
            }

            inline Vector3& operator*=(const Vector3& rhs)
            {
                this->x *= rhs.x;
                this->y *= rhs.y;
                this->z *= rhs.z;
                return *this;
            }

            inline Vector3 operator/(const Vector3& b) const
            {
                return (Vector3(*this) /= b);
            }

            inline Vector3& operator/=(const Vector3& rhs)
            {
                this->x /= rhs.x;
                this->y /= rhs.y;
                this->z /= rhs.z;
                return *this;
            }

            inline Vector3 operator*(const T& b) const
            {
                Vector3 out;
                out.x = x * b;
                out.y = y * b;
                out.z = z * b;
                return out;
            }

            inline Vector3& operator*=(const T& rhs)
            {
                this->x *= rhs;
                this->y *= rhs;
                this->z *= rhs;
                return *this;
            }

            inline Vector3 operator/(const T& b) const
            {
                return (Vector3(*this) /= b);
            }

            inline Vector3& operator/=(const T& rhs)
            {
                this->x /= rhs;
                this->y /= rhs;
                this->z /= rhs;
                return *this;
            }

            inline Vector3& operator=(const Vector3& rhs)
            {
                this->x = rhs.x;
                this->y = rhs.y;
                this->z = rhs.z;
                return *this;
            }

            inline bool operator==(const Vector3& rhs) const
            {
                return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
            }

            inline bool operator!=(const Vector3& rhs) const
            {
                return !(*this == rhs);
            }

            inline operator T*()
            {
                return &x;
            }

            inline Vector3 normalized() const
            {
                if (lengthSquared() == 0)
                {
                    return Vector3::zero;
                }
                return *this / length();
            }

            inline void normalize()
            {
                Vector3 temp = normalized();
                this->x = temp.x;
                this->y = temp.y;
                this->z = temp.z;
            }

            inline T dot(const Vector3& b)
            {
                return x * b.x + y * b.y + z * b.z;
            }

            inline Vector3 cross(const Vector3& rhs) const
            {
                Vector3 out;
                out.x = y * rhs.z - z * rhs.y;
                out.y = z * rhs.x - x * rhs.z;
                out.z = x * rhs.y - y * rhs.x;
                return out;
            }

            static const Vector3 zero;
            static const Vector3 one;
            static const Vector3 right;
            static const Vector3 up;
            static const Vector3 forward;
        };

        template <typename T>
        const Vector3<T> Vector3<T>::zero = Vector3<T>(0, 0, 0);

        template <typename T>
        const Vector3<T> Vector3<T>::one = Vector3<T>(1, 1, 1);

        template <typename T>
        const Vector3<T> Vector3<T>::right = Vector3<T>(1, 0, 0);

        template <typename T>
        const Vector3<T> Vector3<T>::up = Vector3<T>(0, 1, 0);

        template <typename T>
        const Vector3<T> Vector3<T>::forward = Vector3<T>(0, 0, 1);
    }
}
