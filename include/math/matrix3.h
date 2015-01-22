#ifndef MATRIX3_H_
#define MATRIX3_H_

#include <cmath>
#include "vector3.h"

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

                    inline Vector3<T>& operator*(const Vector3<T>& b) const
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
/*
                    inline Matrix3<T> operator/(const Matrix3<T>& b) const
                    {
                        Matrix3<T> out;
                        out.x = x / b.x;
                        out.y = y / b.y;
                        out.z = z / b.z;
                        return out;
                    } 

                    inline Matrix3<T>& operator/=(const Matrix3<T>& rhs)
                    {
                        this->x /= rhs.x;
                        this->y /= rhs.y;
                        this->z /= rhs.z;
                        return *this;
                    }

                    inline Matrix3<T> operator*(const T& b) const
                    {
                        Matrix3<T> out;
                        out.x = x * b;
                        out.y = y * b;
                        out.z = z * b;
                        return out;
                    }

                    inline Matrix3<T>& operator*=(const T& rhs)
                    {
                        this->x *= rhs;
                        this->y *= rhs;
                        this->z *= rhs;
                        return *this;
                    }

                    inline Matrix3<T> operator/(const T& b) const
                    {
                        Matrix3<T> out;
                        out.x = x / b;
                        out.y = y / b;
                        out.z = z / b;
                        return out;
                    }

                    inline Matrix3<T>& operator/=(const T& rhs)
                    {
                        this->x /= rhs;
                        this->y /= rhs;
                        this->z /= rhs;
                        return *this;
                    }
//*/
                    inline Matrix3<T>& operator=(const Matrix3<T>& rhs)
                    {
                        memcpy(this->components, &rhs, sizeof(T) * 9);
                        return *this;
                    }

                    inline bool operator==(const Matrix3<T>& rhs) const
                    {
                        return memcmp(this->components, &rhs, sizeof(T) * 9);
                    }

                    inline bool operator!=(const Matrix3<T>& rhs) const
                    {
                        return !(*this == rhs);
                    }
/*
                    inline T operator[](const int& b)
                    { 
                        return components[b];
                    }
//*/
                    inline operator T* ()
                    { 
                        return &m11;
                    }
/*
                    inline Matrix3<T> normalized()
                    { 
                        if(lengthSquared() == 0)
                        {
                            return Matrix3<T>::zero;
                        }
                        return *this / length();
                    }

                    inline void normalize()
                    {
                        Matrix3<T> temp = normalized();
                        this->x = temp.x;
                        this->y = temp.y;
                        this->z = temp.z;
                    }

                    inline T dot(Matrix3<T>& b)
                    {
                        return x * b.x + y * b.y + z * b.z;
                    }

                    inline Matrix3<T> cross(const Matrix3<T>& rhs) const
                    {
                        Matrix3<T> out;
                        out.x = y * rhs.z - z * rhs.y;
                        out.y = z * rhs.x - x * rhs.z;
                        out.z = x * rhs.y - y * rhs.x;
                        return out;
                    }
                    
                    const static Matrix3<T> zero;
                    const static Matrix3<T> one;
                    const static Matrix3<T> right;
                    const static Matrix3<T> up;
                    const static Matrix3<T> forward;
//*/
                    const static Matrix3<T> identity;
        };
/*
        template<typename T>
        const Matrix3<T> Matrix3<T>::zero = Matrix3<T>(0, 0, 0);

        template<typename T>
        const Matrix3<T> Matrix3<T>::one = Matrix3<T>(1, 1, 1);

        template<typename T>
        const Matrix3<T> Matrix3<T>::right = Matrix3<T>(1, 0, 0);

        template<typename T>
        const Matrix3<T> Matrix3<T>::up = Matrix3<T>(0, 1, 0);

        template<typename T>
        const Matrix3<T> Matrix3<T>::forward = Matrix3<T>(0, 0, 1);
//*/
        template<typename T>
        const Matrix3<T> Matrix3<T>::identity = Matrix3<T>();
    }
}

#endif
