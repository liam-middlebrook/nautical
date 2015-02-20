// vim: ft=swig
%module nauticalua
%extend nautical::math::Vector2 {
    %ignore operator T*;
}
%include "../vector2.i"
