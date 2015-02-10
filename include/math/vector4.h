#pragma once

#include <cmath>

namespace nautical
{
    namespace math
    {
        template <typename T>
        class Vector4
        {
            public:
                    union
                    {
                            struct { T x; T y; T z; T w;};
                            T components[4];
                    };
                    Vector4() : x(0), y(0), z(0), w(0) {}
                    Vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

                    Vector4(T* data)
                    {
                            memcpy(components, data, sizeof(T) * 4);
                    }

                    inline T lengthSquared() const
                    {
                        return x*x + y*y + z*z + w*w;
                    }

                    inline T length() const
                    {
                        return sqrt(lengthSquared());
                    }

                    inline Vector4<T> operator+(const Vector4<T>& b) const
                    {
                        Vector4<T> out;
                        out.x = x + b.x;
                        out.y = y + b.y;
                        out.z = z + b.z;
                        out.w = w + b.w;
                        return out;
                    }

                    inline Vector4<T>& operator+=(const Vector4<T>& rhs)
                    {
                        this->x += rhs.x;
                        this->y += rhs.y;
                        this->z += rhs.z;
                        this->w += rhs.w;
                        return *this;
                    }

                    inline Vector4<T> operator-() const
                    {
                        Vector4<T> out;
                        out.x = -x;
                        out.y = -y;
                        out.z = -z;
                        out.w = -w;
                        return out;
                    }

                    inline Vector4<T> operator-(const Vector4<T>& b) const
                    {
                        Vector4<T> out;
                        out.x = x - b.x;
                        out.y = y - b.y;
                        out.z = z - b.z;
                        out.w = w - b.w;
                        return out;
                    }

                    inline Vector4<T>& operator-=(const Vector4<T>& rhs)
                    {
                        this->x -= rhs.x;
                        this->y -= rhs.y;
                        this->z -= rhs.z;
                        this->w -= rhs.w;
                        return *this;
                    }

                    inline Vector4<T> operator*(const Vector4<T>& b) const
                    {
                        Vector4<T> out;
                        out.x = x * b.x;
                        out.y = y * b.y;
                        out.z = z * b.z;
                        out.w = w * b.w;
                        return out;
                    }

                    inline Vector4<T>& operator*=(const Vector4<T>& rhs)
                    {
                        this->x *= rhs.x;
                        this->y *= rhs.y;
                        this->z *= rhs.z;
                        this->w *= rhs.w;
                        return *this;
                    }

                    inline Vector4<T> operator/(const Vector4<T>& b) const
                    {
                        Vector4<T> out;
                        out.x = x / b.x;
                        out.y = y / b.y;
                        out.z = z / b.z;
                        out.w = w / b.w;
                        return out;
                    }

                    inline Vector4<T>& operator/=(const Vector4<T>& rhs)
                    {
                        this->x /= rhs.x;
                        this->y /= rhs.y;
                        this->z /= rhs.z;
                        this->w /= rhs.w;
                        return *this;
                    }

                    inline Vector4<T> operator*(const T& b) const
                    {
                        Vector4<T> out;
                        out.x = x * b;
                        out.y = y * b;
                        out.z = z * b;
                        out.w = w * b;
                        return out;
                    }

                    inline Vector4<T>& operator*=(const T& rhs)
                    {
                        this->x *= rhs;
                        this->y *= rhs;
                        this->z *= rhs;
                        this->w *= rhs;
                        return *this;
                    }

                    inline Vector4<T> operator/(const T& b) const
                    {
                        Vector4<T> out;
                        out.x = x / b;
                        out.y = y / b;
                        out.z = z / b;
                        out.w = w / b;
                        return out;
                    }

                    inline Vector4<T>& operator/=(const T& rhs)
                    {
                        this->x /= rhs;
                        this->y /= rhs;
                        this->z /= rhs;
                        this->w /= rhs;
                        return *this;
                    }

                    inline Vector4<T>& operator=(const Vector4<T>& rhs)
                    {
                        this->x = rhs.x;
                        this->y = rhs.y;
                        this->z = rhs.z;
                        this->w = rhs.w;
                        return *this;
                    }

                    inline bool operator==(const Vector4<T>& rhs) const
                    {
                        return this->x == rhs.x
                            && this->y == rhs.y
                            && this->z == rhs.z
                            && this->w == rhs.w;
                    }

                    inline bool operator!=(const Vector4<T>& rhs) const
                    {
                        return !(*this == rhs);
                    }

                    inline T operator[](const int& b)
                    {
                        return components[b];
                    }

                    inline operator T* ()
                    {
                        return &x;
                    }

                    inline Vector4<T> normalized()
                    {
                        if(lengthSquared() == 0)
                        {
                            return Vector4<T>::zero;
                        }
                        return *this / length();
                    }

                    inline void normalize()
                    {
                        Vector4<T> temp = normalized();
                        this->x = temp.x;
                        this->y = temp.y;
                        this->z = temp.z;
                        this->w = temp.w;
                    }

                    inline T dot(Vector4<T>& b)
                    {
                        return x * b.x + y * b.y + z * b.z + w * b.w;
                    }

                    const static Vector4<T> zero;
                    const static Vector4<T> one;
                    const static Vector4<T> right;
                    const static Vector4<T> up;
                    const static Vector4<T> forward;
        };

        template<typename T>
        const Vector4<T> Vector4<T>::zero = Vector4<T>(0, 0, 0, 0);

        template<typename T>
        const Vector4<T> Vector4<T>::one = Vector4<T>(1, 1, 1, 1);

        template<typename T>
        const Vector4<T> Vector4<T>::right = Vector4<T>(1, 0, 0, 0);

        template<typename T>
        const Vector4<T> Vector4<T>::up = Vector4<T>(0, 1, 0, 0);

        template<typename T>
        const Vector4<T> Vector4<T>::forward = Vector4<T>(0, 0, 1, 0);
    }
}
