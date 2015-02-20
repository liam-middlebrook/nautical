#pragma once

#include "math/matrix4.h"

namespace nautical
{
    template<typename T>
    class Transform
    {
    public:
        Transform()
        {
        }

        math::Vector3<T> position;
        math::Vector3<T> rotation;
        math::Vector3<T> scale;

        inline math::Matrix4<T> getMatrix()
        {
            return math::Matrix4<T>::scale(scale) *
                   math::Matrix4<T>::rotate(math::Vector3<T>::right,
                                            rotation.x) *
                   math::Matrix4<T>::rotate(math::Vector3<T>::up, rotation.y) *
                   math::Matrix4<T>::rotate(math::Vector3<T>::forward,
                                            rotation.z) *
                   math::Matrix4<T>::translate(position);
        }
    };
}
