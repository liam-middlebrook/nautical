// vim: ft=swig
%include <std_string.i>
%{
#include <sstream>
%}
%ignore operator <<;

%define nautical_accessors
    nautical_lang_accessors
    %ignore operator T*;
    std::string __str__() const {
        std::ostringstream ss;
        ss << *($self);
        return ss.str();
    }
%enddef

%include "lib/engine.i"
%include "lib/gameobject.i"
%include "lib/script.i"
%include "lib/vector2.i"
%include "lib/vector3.i"
%include "lib/vector4.i"
