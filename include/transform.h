#pragma once

#include "math/matrix4.h"

namespace nautical
{
    template<typename T>
    class Transform
    {
    public:
        Transform()
        math::Vector3<T> position;
        math::Vector3<T> rotation;
        math::Vector3<T> scale;

        inline Matrix4<T> getMatrix()
        {
            return Matrix4<T>::scale(scale) *
                   Matrix4<T>::rotate(Vector3<T>::right, rotation.x) *
                   Matrix4<T>::rotate(Vector3<T>::up, rotation.y) *
                   Matrix4<T>::rotate(Vector3<T>::forward, rotation.z) *
                   Matrix4<T>::translate(position);
        }
    };
}
