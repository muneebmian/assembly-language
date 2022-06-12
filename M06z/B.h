#include "std_lib_facilities.h"
class B1
{
    public:
        virtual void vf();
        void f();
        virtual void pvf() = 0;



};
void B1::vf()
{
    cout<<"B1::vf()"<<endl;
}
void B1::f()
{
    cout<<"B1::f()"<<endl;
}
class D1 : public B1
{
    public :
    void f()
    {
    cout<<"D1::f()"<<endl;
    }
    void vf()
    {
    cout<<"D1::vf()"<<endl;
    }
    void pvf()
    {
    cout<<"D1::pvf()"<<endl;
    }
};
class D2 : public D1
{
public:
void pvf()
{
cout<<"D2::pvf()"<<endl;
}
};
class B2
{
public :
virtual void pvf()=0;
};
class D21 :public B2
{
    private:
        string name="D21::pvf()";
    public:
        void pvf();
};
void D21::pvf()
{
cout<<name<<endl;
}
class D22:public B2
{
    private :
        int data=22;
    public:
        void pvf();

};
void D22::pvf()
{
cout<<data<<endl;
}
void f(B2& b2)
{
    b2.pvf();
}