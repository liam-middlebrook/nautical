// vim: ft=swig
%module nauticalpl
%extend nautical::math::Vector2 {
    %ignore operator =;
    %ignore operator [];
    %ignore operator T*;
    %ignore operator *=;
    %ignore operator /=;
}
%extend nautical::math::Vector3 {
    %ignore operator =;
    %ignore operator [];
    %ignore operator T*;
    %ignore operator *=;
    %ignore operator /=;
}
%extend nautical::math::Vector4 {
    %ignore operator =;
    %ignore operator [];
    %ignore operator T*;
    %ignore operator *=;
    %ignore operator /=;
}
%include "../vector2.i"
%include "../vector3.i"
%include "../vector4.i"
