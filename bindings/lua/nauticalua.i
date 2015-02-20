// vim: ft=swig
%module nauticalua
%extend nautical::math::Vector2 {
    %ignore operator T*;
}
%extend nautical::math::Vector3 {
    %ignore operator T*;
}
%extend nautical::math::Vector4 {
    %ignore operator T*;
}
%include "../vector2.i"
%include "../vector3.i"
%include "../vector4.i"
