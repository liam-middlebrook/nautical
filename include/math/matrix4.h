#ifndef MATRIX4_H_
#define MATRIX4_H_

#include <cmath>
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "../util.h"

namespace nautical
{
    namespace math
    {
        template <typename T>
        class Matrix4
        {
            public:
                    union
                    {
                            struct
                            {
                                T m11, m12, m13, m14,
                                  m21, m22, m23, m24,
                                  m31, m32, m33, m34,
                                  m41, m42, m43, m44;
                            };
                            T components[16];
                    };
                    Matrix4() : m11(1), m12(0), m13(0), m14(0),
                                m21(0), m22(1), m23(0), m24(0),
                                m31(0), m32(0), m33(1), m34(0),
                                m41(0), m42(0), m43(0), m44(0) {};

                    Matrix4(T* data)
                    {
                            memcpy(components, data, sizeof(T) * 16);
                    };

                    inline T operator[](const int& b)
                    {
                        return components[b];
                    }

                    inline operator T* ()
                    {
                        return &m11;
                    }

                    inline Matrix4<T> operator+(const Matrix4<T>& b) const
                    {
                        Matrix4<T> out;
                        for(int i = 0; i < 16; ++i)
                        {
                            out.components[i] = components[i] + b.components[i];
                        }
                        return out;
                    }

                    inline Matrix4<T>& operator+=(const Matrix4<T>& rhs)
                    {
                        for(int i = 0; i < 16; ++i)
                        {
                            components[i] += rhs.components[i];
                        }
                        return *this;
                    }

                    inline Matrix4<T> operator-(const Matrix4<T>& b) const
                    {
                        Matrix4<T> out;
                        for(int i = 0; i < 16; ++i)
                        {
                            out.components[i] = components[i] - b.components[i];
                        }
                        return out;
                    }

                    inline Matrix4<T>& operator-=(const Matrix4<T>& rhs)
                    {
                        Matrix4<T> out;
                        for(int i = 0; i < 16; ++i)
                        {
                            components[i] -= rhs.components[i];
                        }
                        return *this;
                    }

                    inline Matrix4<T> operator*(const Matrix4<T>& b) const
                    {
                        Matrix4<T> out;
                        
                        // First column
                        out.m11 = m11 * b.m11 + m12 * b.m21 + m13 * b.m31;
                        out.m21 = m21 * b.m11 + m22 * b.m21 + m23 * b.m31;
                        out.m31 = m31 * b.m11 + m32 * b.m21 + m33 * b.m31;

                        // Second Column
                        out.m12 = m11 * b.m12 + m12 * b.m22 + m13 * b.m32;
                        out.m22 = m21 * b.m12 + m22 * b.m22 + m23 * b.m32;
                        out.m32 = m31 * b.m12 + m32 * b.m22 + m33 * b.m32;

                        // Third Column
                        out.m13 = m11 * b.m13 + m12 * b.m23 + m13 * b.m33;
                        out.m23 = m21 * b.m13 + m22 * b.m23 + m23 * b.m33;
                        out.m33 = m31 * b.m13 + m32 * b.m23 + m33 * b.m33;

                        return out;
                    }

                    inline Matrix4<T>& operator*=(const Matrix4<T>& rhs)
                    {
                        Matrix4<T> out;

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

                        for(int i = 0; i < 9; ++i)
                        {
                            components[i] = out.components[i];
                        }

                        return *this;
                    } 

                    inline Vector3<T> operator*(const Vector4<T>& b) const
                    {
                        Vector3<T> out;

                        out.x = m11 * b.x + m12 * b.y + m13 * b.z + m14 * b.w;
                        out.y = m21 * b.x + m22 * b.y + m23 * b.z + m24 * b.w;
                        out.z = m31 * b.x + m32 * b.y + m33 * b.z + m34 * b.w;
                        out.w = m41 * b.x + m42 * b.y + m43 * b.z + m44 * b.w;

                        return out;
                    }

                    inline Vector3<T>& operator*=(const Vector3<T>& rhs)
                    {
                        Vector3<T> out;

                        out.x = m11 * rhs.x + m12 * rhs.y + m13 * rhs.z + m14 * rhs.w;
                        out.y = m21 * rhs.x + m22 * rhs.y + m23 * rhs.z + m24 * rhs.w;
                        out.z = m31 * rhs.x + m32 * rhs.y + m33 * rhs.z + m34 * rhs.w;
                        out.w = m41 * rhs.x + m42 * rhs.y + m43 * rhs.z + m44 * rhs.w;

                        return Vector3<T>(&out);
                    }

                    inline Matrix4<T>& operator=(const Matrix4<T>& rhs)
                    {
                        memcpy(this->components, &rhs, sizeof(T) * 16);
                        return *this;
                    }

                    inline bool operator==(const Matrix4<T>& rhs) const
                    {
                        for(int i = 0; i < 16; ++i)
                        {
                            if(!tol(components[i], rhs.components[i]))
                            {
                                return false;
                            }
                        }
                        return true;
                    }

                    inline bool operator!=(const Matrix4<T>& rhs) const
                    {
                        return !(*this == rhs);
                    }

                    inline Matrix4<T> transpose()
                    {
                        Matrix4<T> out = Matrix4<T>((T*)this);

                        swap(out.m12, out.m21);
                        swap(out.m13, out.m31);
                        swap(out.m14, out.m41);
                        swap(out.m23, out.m32);
                        swap(out.m24, out.m42);
                        swap(out.m34, out.m43);

                        return out;
                    }

                    inline T determinant()
                    {
                        return m11 * m22 * m33 * m44
                             + m11 * m32 * m43 * m24
                             + m11 * m42 * m23 * m34
                             + m21 * m12 * m43 * m34
                             + m21 * m32 * m13 * m44
                             + m21 * m42 * m33 * m14
                             + m31 * m12 * m23 * m44
                             + m31 * m22 * m43 * m14
                             + m31 * m42 * m13 * m24
                             + m41 * m12 * m33 * m24
                             + m41 * m22 * m13 * m34
                             + m41 * m32 * m23 * m14
                             - m11 * m22 * m43 * m34
                             - m11 * m32 * m23 * m44
                             - m11 * m42 * m33 * m24
                             - m21 * m12 * m33 * m44
                             - m21 * m32 * m43 * m14
                             - m21 * m42 * m13 * m34
                             - m31 * m12 * m43 * m24
                             - m31 * m22 * m13 * m44
                             - m31 * m42 * m23 * m14
                             - m41 * m12 * m23 * m34
                             - m41 * m22 * m33 * m14
                             - m41 * m32 * m13 * m24;
                    }

                    inline Matrix4<T> inverse()
                    {
                        T determinant = this->determinant();

                        Matrix4<T> inv;

                        // Row 1
                        inv.m11 = (m22 * m33 * m44)
                            + (m23 * m34 * m42)
                            + (m24 * m32 * m43)
                            - (m22 * m34 * m43)
                            - (m23 * m32 * m44)
                            - (m24 * m33 * m42);

                        inv.m12 = (m12 * m34 * m43)
                            + (m13 * m32 * m44)
                            + (m14 * m33 * m42)
                            - (m12 * m33 * m44)
                            - (m13 * m34 * m42)
                            - (m14 * m32 * m43);

                        inv.m13 = (m12 * m23 * m44)
                            + (m13 * m24 * m42)
                            + (m14 * m22 * m43)
                            - (m12 * m23 * m43)
                            - (m13 * m22 * m44)
                            - (m14 * m23 * m42);

                        inv.m14 = (m12 * m24 * m33)
                            + (m13 * m22 * m34)
                            + (m14 * m23 * m32)
                            - (m12 * m23 * m34)
                            - (m13 * m24 * m32)
                            - (m14 * m22 * m33);

                        // Row 2
                        inv.m21 = (m21 * m34 * m43)
                            + (m23 * m31 * m44)
                            + (m24 * m33 * m41)
                            - (m21 * m33 * m44)
                            - (m23 * m34 * m41)
                            - (m24 * m31 * m43);

                        inv.m22 = (m11 * m33 * m44)
                            + (m13 * m34 * m41)
                            + (m14 * m31 * m43)
                            - (m11 * m34 * m43)
                            - (m13 * m31 * m44)
                            - (m14 * m33 * m41);

                        inv.m23 = (m11 * m23 * m43)
                            + (m13 * m21 * m44)
                            + (m14 * m23 * m41)
                            - (m11 * m23 * m44)
                            - (m13 * m24 * m41)
                            - (m14 * m21 * m43);

                        inv.m24 = (m11 * m23 * m34)
                            + (m13 * m23 * m31)
                            + (m14 * m21 * m33)
                            - (m11 * m24 * m33)
                            - (m13 * m21 * m34)
                            - (m14 * m23 * m31);

                        //Row 3
                        inv.m31 = (m21 * m32 * m44)
                            + (m22 * m34 * m41)
                            + (m24 * m31 * m42)
                            - (m21 * m34 * m42)
                            - (m22 * m31 * m44)
                            - (m24 * m32 * m41);

                        inv.m32 = (m11 * m34 * m42)
                            + (m12 * m31 * m44)
                            + (m14 * m32 * m41)
                            - (m11 * m32 * m44)
                            - (m12 * m32 * m41)
                            - (m14 * m31 * m42);

                        inv.m33 = (m11 * m22 * m44)
                            + (m12 * m24 * m41)
                            + (m14 * m21 * m42)
                            - (m11 * m24 * m42)
                            - (m12 * m21 * m44)
                            - (m14 * m22 * m41);

                        inv.m34 = (m11 * m24 * m32)
                            + (m12 * m21 * m34)
                            + (m14 * m22 * m31)
                            - (m11 * m22 * m34)
                            - (m12 * m24 * m31)
                            - (m14 * m21 * m32);

                        //Row 4
                        inv.m41 = (m21 * m33 * m42)
                            + (m22 * m31 * m43)
                            + (m23 * m32 * m41)
                            - (m21 * m32 * m43)
                            - (m22 * m33 * m41)
                            - (m23 * m31 * m42);

                        inv.m42 = (m11 * m32 * m43)
                            + (m12 * m33 * m41)
                            + (m13 * m31 * m42)
                            - (m11 * m33 * m42)
                            - (m12 * m31 * m43)
                            - (m13 * m32 * m41);

                        inv.m43 = (m11 * m23 * m42)
                            + (m12 * m21 * m43)
                            + (m13 * m22 * m41)
                            - (m11 * m22 * m43)
                            - (m12 * m23 * m41)
                            - (m13 * m21 * m42);

                        inv.m44 = (m11 * m22 * m33)
                            + (m12 * m23 * m31)
                            + (m13 * m21 * m32)
                            - (m11 * m23 * m32)
                            - (m12 * m21 * m33)
                            - (m13 * m22 * m31);

                        for(int i = 0; i < 16; ++i)
                        {
                            inv.components[i] /= determinant;
                        }

                        return inv;
                    }

                    inline static Matrix4<T> scale(const Vector3<T> scaleVector)
                    {
                        Matrix4<T> out;
                        out.m11 = scaleVector.x;
                        out.m22 = scaleVector.y;
                        out.m33 = scaleVector.z;
                        return out;
                    }

                    inline static Matrix4<T> rotate(const T& angle)
                    {
                        Matrix4<T> out;
                        out.m11 = cos(angle);
                        out.m12 = -sin(angle);
                        out.m21 = -out.m12;
                        out.m22 = out.m11;
                        return out;
                    }

                    inline static Matrix4<T> translate(const Vector3<T> transVector)
                    {
                        Matrix4<T> out;
                        out.m14 = transVector.x;
                        out.m24 = transVector.y;
                        out.m34 = transVector.z;
                        return out;
                    }

                    const static Matrix4<T> identity;
        };

        template<typename T>
        const Matrix4<T> Matrix4<T>::identity = Matrix4<T>();
    }
}

#endif