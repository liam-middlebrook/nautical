// vim: ft=swig
%module nauticalpl

%define nautical_lang_accessors
    %ignore operator =;
    %ignore operator [];
    %ignore operator *=;
    %ignore operator /=;
%enddef

%perlcode %{
use overload '""' => "__str__";
%}

%include "../nautical.i"
