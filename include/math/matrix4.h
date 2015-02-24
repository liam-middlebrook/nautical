#pragma once

#include <cmath>
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix3.h"
#include "../util.h"

namespace nautical
{
    namespace math
    {
        template <typename T>
        class Matrix4
        {
            T m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41,
                m42, m43, m44;

        public:
            Matrix4() : Matrix4{1}
            {
            }

            Matrix4(T v)
                : m11{v}, m12{0}, m13{0}, m14{0}, m21{0}, m22{v}, m23{0},
                  m24{0}, m31{0}, m32{0}, m33{v}, m34{0}, m41{0}, m42{0},
                  m43{0}, m44{v}
            {
            }

            Matrix4(const T* data)
            {
                memcpy(&m11, data, sizeof(T) * 16);
            }

            Matrix4(const Matrix3<T>& m)
            {
                m11 = m.m11;
                m12 = m.m12;
                m13 = m.m13;
                m14 = 0;
                m21 = m.m21;
                m22 = m.m22;
                m23 = m.m23;
                m24 = 0;
                m31 = m.m31;
                m32 = m.m32;
                m33 = m.m33;
                m34 = 0;
                m41 = 0;
                m42 = 0;
                m43 = 0;
            }

            inline T& operator[](int b)
            {
                return (&m11)[b];
            }

            inline const T& operator[](int b) const
            {
                return (&m11)[b];
            }

            inline T& operator()(int row, int col)
            {
                return (&m11)[row * 4 + col];
            }

            inline const T& operator()(int row, int col) const
            {
                return (&m11)[row * 4 + col];
            }

            inline operator T*()
            {
                return &m11;
            }

            inline Matrix4 operator+(const Matrix4& b) const
            {
                return (Matrix4(*this) += b);
            }

            inline Matrix4& operator+=(const Matrix4& rhs)
            {
                for (int i = 0; i < 16; ++i)
                {
                    (*this)[i] += rhs[i];
                }
                return *this;
            }

            inline Matrix4 operator-(const Matrix4& b) const
            {
                return (Matrix4(*this) -= b);
            }

            inline Matrix4& operator-=(const Matrix4& rhs)
            {
                for (int i = 0; i < 16; ++i)
                {
                    (*this)[i] -= rhs[i];
                }
                return *this;
            }

            inline Matrix4 operator*(const Matrix4& b) const
            {
                return (Matrix4(*this) *= b);
            }

            inline Matrix4& operator*=(const Matrix4& rhs)
            {
                Matrix4 out;

                // First column
                out.m11 = m11 * rhs.m11 + m12 * rhs.m21 + m13 * rhs.m31 +
                          m14 * rhs.m41;
                out.m21 = m21 * rhs.m11 + m22 * rhs.m21 + m23 * rhs.m31 +
                          m24 * rhs.m41;
                out.m31 = m31 * rhs.m11 + m32 * rhs.m21 + m33 * rhs.m31 +
                          m34 * rhs.m41;
                out.m41 = m41 * rhs.m11 + m42 * rhs.m21 + m43 * rhs.m31 +
                          m44 * rhs.m41;

                // Second Column
                out.m12 = m11 * rhs.m12 + m12 * rhs.m22 + m13 * rhs.m32 +
                          m14 * rhs.m42;
                out.m22 = m21 * rhs.m12 + m22 * rhs.m22 + m23 * rhs.m32 +
                          m24 * rhs.m42;
                out.m32 = m31 * rhs.m12 + m32 * rhs.m22 + m33 * rhs.m32 +
                          m34 * rhs.m42;
                out.m42 = m41 * rhs.m12 + m42 * rhs.m22 + m43 * rhs.m32 +
                          m44 * rhs.m42;

                // Third Column
                out.m13 = m11 * rhs.m13 + m12 * rhs.m23 + m13 * rhs.m33 +
                          m14 * rhs.m43;
                out.m23 = m21 * rhs.m13 + m22 * rhs.m23 + m23 * rhs.m33 +
                          m24 * rhs.m43;
                out.m33 = m31 * rhs.m13 + m32 * rhs.m23 + m33 * rhs.m33 +
                          m34 * rhs.m43;
                out.m43 = m41 * rhs.m13 + m42 * rhs.m23 + m43 * rhs.m33 +
                          m44 * rhs.m43;

                // Fourth Column
                out.m14 = m11 * rhs.m14 + m12 * rhs.m24 + m13 * rhs.m34 +
                          m14 * rhs.m44;
                out.m24 = m21 * rhs.m14 + m22 * rhs.m24 + m23 * rhs.m34 +
                          m24 * rhs.m44;
                out.m34 = m31 * rhs.m14 + m32 * rhs.m24 + m33 * rhs.m34 +
                          m34 * rhs.m44;
                out.m44 = m41 * rhs.m14 + m42 * rhs.m24 + m43 * rhs.m34 +
                          m44 * rhs.m44;

                for (int i = 0; i < 16; ++i)
                {
                    (*this)[i] = out[i];
                }

                return *this;
            }

            inline Vector4<T> operator*(const Vector4<T>& b) const
            {
                return (Matrix4(*this) *= b);
            }

            inline Vector4<T> operator*=(const Vector4<T>& rhs)
            {
                Vector4<T> out;

                out.x = m11 * rhs.x + m12 * rhs.y + m13 * rhs.z + m14 * rhs.w;
                out.y = m21 * rhs.x + m22 * rhs.y + m23 * rhs.z + m24 * rhs.w;
                out.z = m31 * rhs.x + m32 * rhs.y + m33 * rhs.z + m34 * rhs.w;
                out.w = m41 * rhs.x + m42 * rhs.y + m43 * rhs.z + m44 * rhs.w;

                return out;
            }

            inline Matrix4& operator=(const Matrix4& rhs)
            {
                memcpy(&m11, &rhs, sizeof(T) * 16);
                return *this;
            }

            inline bool operator==(const Matrix4& rhs) const
            {
                for (int i = 0; i < 16; ++i)
                {
                    if (!tol((*this)[i], rhs[i]))
                    {
                        return false;
                    }
                }
                return true;
            }

            inline bool operator!=(const Matrix4& rhs) const
            {
                return !(*this == rhs);
            }

            inline void transpose()
            {
                swap(m12, m21);
                swap(m13, m31);
                swap(m14, m41);
                swap(m23, m32);
                swap(m24, m42);
                swap(m34, m43);
            }

            inline Matrix4 transposed() const
            {
                Matrix4 out = Matrix4(*this);
                out.transpose();
                return out;
            }

            inline T determinant()
            {
                return m11 * m22 * m33 * m44 + m11 * m32 * m43 * m24 +
                       m11 * m42 * m23 * m34 + m21 * m12 * m43 * m34 +
                       m21 * m32 * m13 * m44 + m21 * m42 * m33 * m14 +
                       m31 * m12 * m23 * m44 + m31 * m22 * m43 * m14 +
                       m31 * m42 * m13 * m24 + m41 * m12 * m33 * m24 +
                       m41 * m22 * m13 * m34 + m41 * m32 * m23 * m14 -
                       m11 * m22 * m43 * m34 - m11 * m32 * m23 * m44 -
                       m11 * m42 * m33 * m24 - m21 * m12 * m33 * m44 -
                       m21 * m32 * m43 * m14 - m21 * m42 * m13 * m34 -
                       m31 * m12 * m43 * m24 - m31 * m22 * m13 * m44 -
                       m31 * m42 * m23 * m14 - m41 * m12 * m23 * m34 -
                       m41 * m22 * m33 * m14 - m41 * m32 * m13 * m24;
            }

            inline Matrix4 inverse()
            {
                T determinant = this->determinant();

                Matrix4 inv;

                // Row 1
                inv.m11 = (m22 * m33 * m44) + (m23 * m34 * m42) +
                          (m24 * m32 * m43) - (m22 * m34 * m43) -
                          (m23 * m32 * m44) - (m24 * m33 * m42);

                inv.m12 = (m12 * m34 * m43) + (m13 * m32 * m44) +
                          (m14 * m33 * m42) - (m12 * m33 * m44) -
                          (m13 * m34 * m42) - (m14 * m32 * m43);

                inv.m13 = (m12 * m23 * m44) + (m13 * m24 * m42) +
                          (m14 * m22 * m43) - (m12 * m24 * m43) -
                          (m13 * m22 * m44) - (m14 * m23 * m42);

                inv.m14 = (m12 * m24 * m33) + (m13 * m22 * m34) +
                          (m14 * m23 * m32) - (m12 * m23 * m34) -
                          (m13 * m24 * m32) - (m14 * m22 * m33);

                // Row 2
                inv.m21 = (m21 * m34 * m43) + (m23 * m31 * m44) +
                          (m24 * m33 * m41) - (m21 * m33 * m44) -
                          (m23 * m34 * m41) - (m24 * m31 * m43);

                inv.m22 = (m11 * m33 * m44) + (m13 * m34 * m41) +
                          (m14 * m31 * m43) - (m11 * m34 * m43) -
                          (m13 * m31 * m44) - (m14 * m33 * m41);

                inv.m23 = (m11 * m24 * m43) + (m13 * m21 * m44) +
                          (m14 * m23 * m41) - (m11 * m23 * m44) -
                          (m13 * m24 * m41) - (m14 * m21 * m43);

                inv.m24 = (m11 * m23 * m34) + (m13 * m24 * m31) +
                          (m14 * m21 * m33) - (m11 * m24 * m33) -
                          (m13 * m21 * m34) - (m14 * m23 * m31);

                // Row 3
                inv.m31 = (m21 * m32 * m44) + (m22 * m34 * m41) +
                          (m24 * m31 * m42) - (m21 * m34 * m44) -
                          (m22 * m31 * m44) - (m24 * m32 * m41);

                inv.m32 = (m11 * m34 * m42) + (m12 * m31 * m44) +
                          (m14 * m32 * m41) - (m11 * m32 * m44) -
                          (m12 * m34 * m41) - (m14 * m31 * m42);

                inv.m33 = (m11 * m22 * m44) + (m12 * m24 * m41) +
                          (m14 * m21 * m42) - (m11 * m24 * m42) -
                          (m12 * m21 * m44) - (m14 * m22 * m41);

                inv.m34 = (m11 * m24 * m32) + (m12 * m21 * m34) +
                          (m14 * m22 * m31) - (m11 * m22 * m34) -
                          (m12 * m24 * m31) - (m14 * m21 * m32);

                // Row 4
                inv.m41 = (m21 * m33 * m42) + (m22 * m31 * m43) +
                          (m23 * m32 * m41) - (m21 * m32 * m43) -
                          (m22 * m33 * m41) - (m23 * m31 * m42);

                inv.m42 = (m11 * m32 * m43) + (m12 * m33 * m41) +
                          (m13 * m31 * m42) - (m11 * m33 * m42) -
                          (m12 * m31 * m43) - (m13 * m32 * m41);

                inv.m43 = (m11 * m23 * m42) + (m12 * m21 * m43) +
                          (m13 * m22 * m41) - (m11 * m22 * m43) -
                          (m12 * m23 * m41) - (m13 * m21 * m42);

                inv.m44 = (m11 * m22 * m33) + (m12 * m23 * m31) +
                          (m13 * m21 * m32) - (m11 * m23 * m32) -
                          (m12 * m21 * m33) - (m13 * m22 * m31);

                for (int i = 0; i < 16; ++i)
                {
                    inv[i] /= determinant;
                }

                return inv;
            }

            inline static Matrix4 scale(const Vector3<T>& scaleVector)
            {
                Matrix4 out;
                out.m11 = scaleVector.x;
                out.m22 = scaleVector.y;
                out.m33 = scaleVector.z;
                return out;
            }

            inline static Matrix4 rotate(const Vector3<T>& axis, const T& angle)
            {
                Vector3<T> a = axis.normalized();

                Matrix4 out;

                T c = cos(angle);
                T s = sin(angle);
                out.m11 = c + a.x * a.x * (1.0 - c);
                out.m12 = a.x * a.y * (1.0 - c) - a.z * s;
                out.m13 = a.x * a.z * (1.0 - c) + a.y * s;
                out.m14 = 0;

                out.m21 = a.y * a.x * (1.0 - c) + a.z * s;
                out.m22 = c + a.y * a.y * (1.0 - c);
                out.m23 = a.y * a.z * (1.0 - c) - a.x * s;
                out.m24 = 0;

                out.m31 = a.z * a.x * (1.0 - c) - a.y * s;
                out.m32 = a.z * a.y * (1.0 - c) + a.x * s;
                out.m33 = c + a.z * a.z * (1.0 - c);
                out.m34 = 0;

                out.m41 = 0;
                out.m42 = 0;
                out.m43 = 0;
                out.m44 = 1;
                return out;
            }

            inline static Matrix4 translate(const Vector3<T>& transVector)
            {
                Matrix4 out;
                out.m14 = transVector.x;
                out.m24 = transVector.y;
                out.m34 = transVector.z;
                return out;
            }

            const static Matrix4 identity;
        };

        template <typename T>
        const Matrix4<T> Matrix4<T>::identity = Matrix4<T>();
    }
}
