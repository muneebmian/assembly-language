#include"std_lib_facilities.h"
#include"B.h"

int main()
{
    //B1 b; error as pure virtual function
    D1 d;
    d.f();
    d.vf();
    d.pvf();

    B1* b;
    b = &d;
    b->f();
    b->vf();
    b->pvf();

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    D21 d21;
    
    d21.pvf();
    
    D22 d22;
  
    d22.pvf();
    return 0;
}