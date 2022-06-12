#include"S.h"
template<typename T>
S<T>::S(T v)
{
   val = v;
}
template<typename T>
T S<T>::getValue()const
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
   cin >> temp;
   s = temp;
   return is;
}
template<typename T>
ostream& operator<<(ostream& os, const S<T>& s)
{
   os << s.getValue() << " ";
   return os;
}
template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
   T t1, t2, t3;
   vector<T> temp;
   char ch;
   is >> t1 >> ch >> t2 >> ch >> t3;
   temp.push_back(t1);
   temp.push_back(t2);
   temp.push_back(t3);
   v = temp;
   return is;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
   for (int i = 0; i < v.size(); i++)
   {
       os << v[i] << ", ";
   }
   os << endl;
   return os;
}