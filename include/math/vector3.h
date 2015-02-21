#pragma once

#include <cmath>
#include <ostream>

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

            friend std::ostream& operator<<(std::ostream& os, const Vector3& v)
            {
                return os << "<" << v.x << ", " << v.y << ", " << v.z << ">";
            }

#ifndef SWIG
            static const Vector3 zero;
            static const Vector3 one;
            static const Vector3 right;
            static const Vector3 up;
            static const Vector3 forward;
#endif

            static const Vector3 ZERO()
            {
                return Vector3(0, 0, 0);
            }
            static const Vector3 ONE()
            {
                return Vector3(1, 1, 1);
            }
            static const Vector3 RIGHT()
            {
                return Vector3(1, 0, 0);
            }
            static const Vector3 UP()
            {
                return Vector3(0, 1, 0);
            }
            static const Vector3 FORWARD()
            {
                return Vector3(0, 0, 1);
            }
        };

#ifndef SWIG
        template <typename T>
        const Vector3<T> Vector3<T>::zero = Vector3<T>::ZERO();

        template <typename T>
        const Vector3<T> Vector3<T>::one = Vector3<T>::ONE();

        template <typename T>
        const Vector3<T> Vector3<T>::right = Vector3<T>::RIGHT();

        template <typename T>
        const Vector3<T> Vector3<T>::up = Vector3<T>::UP();

        template <typename T>
        const Vector3<T> Vector3<T>::forward = Vector3<T>::FORWARD();
#endif
    }
}
