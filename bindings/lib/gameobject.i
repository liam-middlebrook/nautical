// vim: ft=swig
%{
#include "transform.h"
#include "gameobject.h"
%}
%include "transform.h"
%template(Transform_f) nautical::Transform<float>;
%include "gameobject.h"
