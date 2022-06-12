#include "../std_lib_facilities.h"
#include "Matrices.h"
using namespace Matrices;

int main()
{
    
    Matrices::Matrix a(2,2);
    Matrices::Matrix b(2,4);
    Matrices::Matrix c(2,4);
    a(0,0) = 0;
    a(0,1) = -1;
    a(1,0) = 1;
    a(1,1) = 0;
    b(0,0) = 1;
    b(0,1) =  0.866025;
    b(0,2) = 1;
    b(0,3) = 0.5;
    b(1,0) = 0;
    b(1,1) = 0.5;
    b(1,2) = 1;
    b(1,3) =  0.866025;
    cout << "a:" << endl;
    cout << a << endl << endl;

    cout << "b:" << endl;
    cout  <<  b << endl << endl;
    
   
    try{
        cout << "c = b + b:" << endl;
        c = b  + b;
        cout << c << endl;}

    catch(...)
        {cout << "Error has occured" << endl;  }
    
    
    try{
        cout << "c = a * b:"<< endl;
        c = a * b;
        cout  << c << endl << endl;}

    catch(...)
        {cout << "Error has occured" << endl;  }
    
    
    return 0;
}