#pragma once

#include <cmath>
#include "vector2.h"
#include "vector3.h"
#include "../util.h"

namespace nautical
{
    namespace math
    {
        template <typename T>
        class Matrix3
        {
            T m11, m12, m13, m21, m22, m23, m31, m32, m33;

        public:
            Matrix3() : Matrix3{1}
            {
            }

            Matrix3(T v)
                : m11{v}, m12{0}, m13{0}, m21{0}, m22{v}, m23{0}, m31{0},
                  m32{0}, m33{v}
            {
            }

            Matrix3(const T* data)
            {
                memcpy(&m11, data, sizeof(T) * 9);
            }

            inline T& operator[](int idx)
            {
                return (&m11)[idx];
            }

            inline const T& operator[](int idx) const
            {
                return (&m11)[idx];
            }

            inline T& operator()(int row, int col)
            {
                return (&m11)[row * 3 + col];
            }

            inline const T& operator()(int row, int col) const
            {
                return (&m11)[row * 3 + col];
            }

            inline operator T*()
            {
                return &m11;
            }

            inline Matrix3 operator+(const Matrix3& b) const
            {
                return (Matrix3(*this) += b);
            }

            inline Matrix3 operator+=(const Matrix3& rhs)
            {
                for (int i = 0; i < 9; ++i)
                {
                    (*this)[i] += rhs[i];
                }
                return *this;
            }

            inline Matrix3 operator-(const Matrix3& b) const
            {
                return (Matrix3(*this) -= b);
            }

            inline Matrix3 operator-=(const Matrix3& rhs)
            {
                for (int i = 0; i < 9; ++i)
                {
                    (*this)[i] -= rhs[i];
                }
                return *this;
            }

            inline Matrix3 operator*(const Matrix3& b) const
            {
                return (Matrix3(*this) *= b);
            }

            inline Matrix3 operator*=(const Matrix3& rhs)
            {
                Matrix3 out;

                // First column
                out.m11 = m11 * rhs.m11 + m12 * rhs.m21 + m13 * rhs.m31;
                out.m21 = m21 * rhs.m11 + m22 * rhs.m21 + m23 * rhs.m31;
                out.m31 = m31 * rhs.m11 + m32 * rhs.m21 + m33 * rhs.m31;

                // Second Column
                out.m12 = m11 * rhs.m12 + m12 * rhs.m22 + m13 * rhs.m32;
                out.m22 = m21 * rhs.m12 + m22 * rhs.m22 + m23 * rhs.m32;
                out.m32 = m31 * rhs.m12 + m32 * rhs.m22 + m33 * rhs.m32;

                // Third Column
                out.m13 = m11 * rhs.m13 + m12 * rhs.m23 + m13 * rhs.m33;
                out.m23 = m21 * rhs.m13 + m22 * rhs.m23 + m23 * rhs.m33;
                out.m33 = m31 * rhs.m13 + m32 * rhs.m23 + m33 * rhs.m33;

                for (int i = 0; i < 9; ++i)
                {
                    (*this)[i] = out[i];
                }

                return *this;
            }

            inline Vector3<T> operator*(const Vector3<T>& b) const
            {
                return (Matrix3(*this) *= b);
            }

            inline Vector3<T> operator*=(const Vector3<T>& rhs)
            {
                Vector3<T> out;

                out.x = m11 * rhs.x + m12 * rhs.y + m13 * rhs.z;
                out.y = m21 * rhs.x + m22 * rhs.y + m23 * rhs.z;
                out.z = m31 * rhs.x + m32 * rhs.y + m33 * rhs.z;

                return out;
            }

            inline Matrix3 operator=(const Matrix3& rhs)
            {
                memcpy(&m11, &rhs, sizeof(T) * 9);
                return *this;
            }

            inline bool operator==(const Matrix3& rhs) const
            {
                for (int i = 0; i < 9; ++i)
                {
                    if (!tol((*this)[i], rhs[i]))
                    {
                        return false;
                    }
                }
                return true;
            }

            inline bool operator!=(const Matrix3& rhs) const
            {
                return !(*this == rhs);
            }

            inline void transpose()
            {
                swap(m12, m21);
                swap(m13, m31);
                swap(m23, m32);
            }

            inline Matrix3 transposed() const
            {
                Matrix3 out = Matrix3(*this);
                out.transpose();
                return out;
            }

            inline T determinant() const
            {
                return m11 * ((m22 * m33) - (m23 * m32)) -
                       m12 * ((m21 * m33) - (m23 * m31)) +
                       m13 * ((m21 * m32) - (m22 * m31));
            }

            inline Matrix3 inverse() const
            {
                T det = determinant();

                Matrix3 inv;

                inv.m11 = (m22 * m33) - (m23 * m32);
                inv.m12 = (m13 * m32) - (m12 * m33);
                inv.m13 = (m12 * m23) - (m13 * m22);

                inv.m21 = (m23 * m31) - (m21 * m33);
                inv.m22 = (m11 * m33) - (m13 * m31);
                inv.m23 = (m13 * m21) - (m11 * m23);

                inv.m31 = (m21 * m32) - (m22 * m31);
                inv.m32 = (m12 * m31) - (m11 * m32);
                inv.m33 = (m11 * m22) - (m12 * m21);

                for (int i = 0; i < 9; ++i)
                {
                    inv[i] /= det;
                }

                return inv;
            }

            inline static Matrix3 scale(const Vector2<T>& scaleVector)
            {
                Matrix3 out;
                out.m11 = scaleVector.x;
                out.m22 = scaleVector.y;
                return out;
            }

            inline static Matrix3 rotate(const T& angle)
            {
                Matrix3 out;
                out.m11 = cos(angle);
                out.m12 = -sin(angle);
                out.m21 = -out.m12;
                out.m22 = out.m11;
                return out;
            }

            inline static Matrix3 translate(const Vector2<T> transVector)
            {
                Matrix3 out;
                out.m13 = transVector.x;
                out.m23 = transVector.y;
                return out;
            }

            const static Matrix3 identity;
        };

        template <typename T>
        const Matrix3<T> Matrix3<T>::identity = Matrix3<T>();
    }
}
