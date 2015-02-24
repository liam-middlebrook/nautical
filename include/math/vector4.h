#pragma once

#include <cmath>
#include <ostream>
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

            Vector4() : Vector4{0, 0, 0, 0}
            {
            }

            Vector4(T x, T y, T z, T w) : x{x}, y{y}, z{z}, w{w}
            {
            }

            Vector4(const Vector2<T>& rval) : Vector4{rval.x, rval.y, 0, 0}
            {
            }

            Vector4(const Vector3<T>& rval) : Vector4{rval.x, rval.y, rval.z, 0}
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

            friend std::ostream& operator<<(std::ostream& os, const Vector4& v)
            {
                return os << "<" << v.x << ", " << v.y << ", " << v.z << ", "
                          << v.w << ">";
            }

#ifndef SWIG
            static const Vector4 zero;
            static const Vector4 one;
            static const Vector4 right;
            static const Vector4 up;
            static const Vector4 forward;
            static const Vector4 ana;
#endif

            static constexpr Vector4 ZERO()
            {
                return Vector4(0, 0, 0, 0);
            };
            static constexpr Vector4 ONE()
            {
                return Vector4(1, 1, 1, 1);
            };
            static constexpr Vector4 RIGHT()
            {
                return Vector4(1, 0, 0, 0);
            };
            static constexpr Vector4 UP()
            {
                return Vector4(0, 1, 0, 0);
            };
            static constexpr Vector4 FORWARD()
            {
                return Vector4(0, 0, 1, 0);
            };
            static constexpr Vector4 ANA()
            {
                return Vector4(0, 0, 0, 1);
            };
        };

#ifndef SWIG
        template <typename T>
        const Vector4<T> Vector4<T>::zero = Vector4<T>::ZERO();

        template <typename T>
        const Vector4<T> Vector4<T>::one = Vector4<T>::ONE();

        template <typename T>
        const Vector4<T> Vector4<T>::right = Vector4<T>::RIGHT();

        template <typename T>
        const Vector4<T> Vector4<T>::up = Vector4<T>::UP();

        template <typename T>
        const Vector4<T> Vector4<T>::forward = Vector4<T>::FORWARD();

        template <typename T>
        const Vector4<T> Vector4<T>::ana = Vector4<T>::ANA();
#endif
    }
}
