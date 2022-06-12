#include"std_lib_facilities.h"
#ifndef S_H
#define S_H


template<typename T> struct S
{
private:
   T val;
public:
   /* function get that returns a reference to val and takes no parameters*/
   T get() const;
   /*public constructor that takes a T and assigns val.*/
   S(T v);

   S<T>& operator=(const T& t);

};
template<typename T>
S<T>::S(T v)
{
   val = v;
}
template<typename T>
T S<T>::get() const
{

   return val;
}
template<typename T>
S<T>& S<T>::operator=(const T& t)
{
   this->val = t;
   return *this;
}
template<typename T>
istream& operator>>(istream& is, S<T>& s)
{
   T temp;
   is >> temp;
   s = temp;
   return is;
}
template<typename T>
ostream& operator<<(ostream& os, const S<T>& s)
{
   os << s.get() << " ";
   return os;
}
template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
   T t1, t2, t3;
   vector<T> temp;
   char ch;
   is >> ch >> t1 >> ch >> t2  >> ch >> t3 >>ch;
   temp.push_back(t1);
   temp.push_back(t2);
   temp.push_back(t3);
   v = temp;
   return is;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "{" << v[0] << ", " << v[1] << ", " << v[2] << "}";
 
   os << endl;
   return os;
}


#endif
