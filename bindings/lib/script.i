// vim: ft=swig
%{
#include "script.h"
%}
%feature("director") nautical::script::Script;
%inline %{
void testScript(nautical::script::Script& scr)
{
    printf("At the start of testScript\n");
    scr.init();
    scr.update();
    scr.lateUpdate();
    printf("At the end of testScript\n");
}
%}
%include "script.h"
