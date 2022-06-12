#include"std_lib_facilities.h"

#include "S.h"

int main()
{
   S<int> s1(0); S<char>s2(' '); S<double> s3(4.5);
   S<string>s4("");
   vector<int> ints;
   S<vector<int>> s(ints);
   cin >> s1;
   cout << s1 << endl;

   
   cin >> s2;
   cout  << s2 << endl;

   
   cin >> s3;
   cout  << s3 << endl;

   
   cin >> s4;
   cout << s4 << endl;
   cin >> s;

   cout << s;
   return 0;
}