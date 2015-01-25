#ifndef MATRIX3_H_
#define MATRIX3_H_

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
            public:
                    union
                    {
                            struct
                            {
                                T m11, m12, m13,
                                  m21, m22, m23,
                                  m31, m32, m33;
                            };
                            T components[9];
                    };
                    Matrix3() : m11(1), m12(0), m13(0),
                                m21(0), m22(1), m23(0),
                                m31(0), m32(0), m33(1) {};

                    Matrix3(T* data)
                    {
                            memcpy(components, data, sizeof(T) * 9);
                    };

                    inline T operator[](const int& b)
                    {
                        return components[b];
                    }

                    inline operator T* ()
                    {
                        return &m11;
                    }

                    inline Matrix3<T> operator+(const Matrix3<T>& b) const
                    {
    `                   Matrix3<T> out;
                        for(int i = 0; i < 9; ++i)
                        {
                            out.components[i] = components[i] + b.components[i];
                        }
                        return out;
                    }

                    inline Matrix3<T>& operator+=(const Matrix3<T>& rhs)
                    {
                        Matrix3<T> out;
                        for(int i = 0; i < 9; ++i)
                        {
                            out.components[i] = components[i] + b.components[i];
                        }
                        return Matrix3<T>(&out);
                    }

                    inline Matrix3<T> operator-(const Matrix3<T>& b) const
                    {
    `                   Matrix3<T> out;
                        for(int i = 0; i < 9; --i)
                        {
                            out.components[i] = components[i] - b.components[i];
                        }
                        return out;
                    }

                    inline Matrix3<T>& operator-=(const Matrix3<T>& rhs)
                    {
                        Matrix3<T> out;
                        for(int i = 0; i < 9; ++i)
                        {
                            out.components[i] = components[i] - b.components[i];
                        }
                        return Matrix3<T>(&out);
                    }

                    inline Matrix3<T> operator*(const Matrix3<T>& b) const
                    {
                        Matrix3<T> out;
                        
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

                    inline Matrix3<T>& operator*=(const Matrix3<T>& rhs)
                    {
                        Matrix3<T> out;

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


                        return Matrix3<T>(&out);
                    } 

                    inline Vector3<T> operator*(const Vector3<T>& b) const
                    {
                        Vector3<T> out;

                        out.x = m11 * b.x + m12 * b.y + m13 * b.z;
                        out.y = m21 * b.x + m22 * b.y + m23 * b.z;
                        out.z = m31 * b.x + m32 * b.y + m33 * b.z;

                        return out;
                    }

                    inline Vector3<T>& operator*=(const Vector3<T>& rhs)
                    {
                        Vector3<T> out;

                        out.x = m11 * rhs.x + m12 * rhs.y + m13 * rhs.z;
                        out.y = m21 * rhs.x + m22 * rhs.y + m23 * rhs.z;
                        out.z = m31 * rhs.x + m32 * rhs.y + m33 * rhs.z;

                        return Vector3<T>(&out);
                    }

                    inline Matrix3<T>& operator=(const Matrix3<T>& rhs)
                    {
                        memcpy(this->components, &rhs, sizeof(T) * 9);
                        return *this;
                    }

                    inline bool operator==(const Matrix3<T>& rhs) const
                    {
                        for(int i = 0; i < 9; ++i)
                        {
                            if(!tol(components[i], rhs.components[i]))
                            {
                                return false;
                            }
                        }
                        return true;
                    }

                    inline bool operator!=(const Matrix3<T>& rhs) const
                    {
                        return !(*this == rhs);
                    }

                    inline Matrix3<T> transpose()
                    {
                        Matrix3<T> out = Matrix3<T>((T*)this);

                        swap(out.m12, out.m21);
                        swap(out.m13, out.m31);
                        swap(out.m23, out.m32);

                        return out;
                    }

                    inline T determinant()
                    {
                        return m11 * ((m22 * m33) - (m23 * m32))
                             - m12 * ((m21 * m33) - (m23 * m31))
                             + m13 * ((m21 * m32) - (m22 * m31));
                    }
                    inline static Matrix3<T> scale(const Vector2<T> scaleVector)
                    {
                        Matrix3<T> out;
                        out.m11 = scaleVector.x;
                        out.m22 = scaleVector.y;
                        return out;
                    }

                    inline static Matrix3<T> rotate(const T& angle)
                    {
                        Matrix3<T> out;
                        out.m11 = cos(angle);
                        out.m12 = -sin(angle);
                        out.m21 = -out.m12;
                        out.m22 = out.m11;
                        return out;
                    }

                    inline static Matrix3<T> translate(const Vector2<T> transVector)
                    {
                        Matrix3<T> out;
                        out.m13 = transVector.x;
                        out.m23 = transVector.y;
                        return out;
                    }

                    const static Matrix3<T> identity;
        };

        template<typename T>
        const Matrix3<T> Matrix3<T>::identity = Matrix3<T>();
    }
}

#endif
