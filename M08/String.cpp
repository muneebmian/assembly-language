#include <iostream>
#include <cstring>
#include <fstream>
#include "String.h"
using std::ostream; using std::istream; using std::cin; using std::cout; using std::endl;
using std::ofstream; using std::ifstream; using std::streambuf; using std::ios;

namespace String
{
string::string() :sz{0}, pChars{nullptr}, space(0){}

string::string(const char* s)
{
    sz = strlen(s);
    space = sz;
    pChars = new char[sz];

    int i = 0;
    while (s[i] != '\0') 
        {
            pChars[i] = s[i];
            ++i;
        }
    
}
string::~string() 
{ 
    delete[] pChars;
}
string::string(const string& s)
{
    sz = s.sz;
    pChars = new char [sz];
    for(unsigned i = 0; i < size(); i++)
        pChars[i] = s.pChars[i];
     
}
    
string& string::operator=(const string& s)
{
    
	//if (pChars==s.pChars) 
    //{
        delete [] pChars;
      //  return *this;
    //}	
    sz = s.sz;
    space = s.space;
  
   pChars = new char [sz];
   for (unsigned i = 0; i < size(); i++)
       pChars[i] = s.pChars[i];
  
   return *this;
}
string& string::operator=(const char* s)
{
    delete [] pChars;
    sz = strlen(s);
    space = sz;
    pChars = new char[sz];
    int i =0;
    while(s[i] != '\0'){
           pChars[i] = s[i];
           i++;
       }
    return *this;

}
string& string::operator=(string&& s)
{
    cout << "Move" << endl;
    delete [] pChars;
    pChars = s.pChars;
    sz=s.sz;
    space = s.space;
    s.pChars = nullptr;
    s.sz = 0;
    return *this;
}
const char& string::operator[](size_t pos) const
{
   return pChars[pos];
}
char& string::operator[](size_t pos)
{
   return pChars[pos];
}

bool operator == (const string& lhs, const string& rhs )
{
    if(lhs.size() != rhs.size())
    {
        return false;
    }
    for(size_t i =0; i < lhs.size();i++)
    {
        if(lhs[i] != rhs[i])
        {
            return false;
        }
    }
    return true;   
}
 bool operator==(const string& lhs, const char* rhs)
 { 
    if(lhs.size() != strlen(rhs))
    {
        return false;
    }
    for(size_t i = 0; i < lhs.size();i++)
    {
        if(lhs[i] != rhs[i])
        {
            return false;
        }
    }
    
    return true;
 }
 string operator+(const string& lhs, const string& rhs)
 {
   string temp = "";
   for(unsigned i =0; i < lhs.size();i++)
   {
       temp.push_back(lhs[i]);
   }
   for(unsigned j =0; j < rhs.size();j++)
   {
       temp.push_back(rhs[j]);
   }

   return temp;

 }
 
 ostream& operator<<(ostream& os, const string& s)
 {  int i = 0;
    while(os << s[i])
        i++;
    return os;
 }
 istream& operator>>(istream& is, string& s)
 {
    char chr;
    while(is.get(chr))
    {
        if(isspace(chr))
        {
            if(s.size() > 0)
            {
                break;
            }
        }
        else
        {
            s.push_back(chr);
        }
        
    }
    return is;
}
 bool operator>( const string & lhs, const string & rhs )
{
    for(unsigned i =0 ; i<lhs.size();i++)
    {
           /* if(lhs[i] == rhs[i])
            {
                continue;
            }*/
            if(lhs[i] > rhs[i])
            {
                return true;
            }
            else if(rhs[i] > lhs[i])
            {
                return false;
            }
    }
    return lhs.size() > rhs.size();
  

}
void string::push_back(const char c)
{

    if(sz==0)
    {
        reserve(8);
    }
    else if (sz==space)
    {
        reserve(2*space);
    }
    pChars[sz] = c;
    ++sz;
}
size_t string::find(const char* s, size_t pos) const
{
    for(unsigned i = pos;i < size();i++)
    {
        if(pChars[i] == s[0])
        {
            for(unsigned j = pos;j < size();j++)
            {
                if(pChars[j] != s[j])
                {
                    return i;
                }
                else if(s[j] == '\0')
                {
                    return i;
                }
            }
        }
    }
    return SIZE_MAX;

}
void string::reserve(size_t n)
{
    if(n <=space)
        return;
    char* x = new char[n];
    for(unsigned i = 0;i <sz;i++)
    {
        x[i] = pChars[i];
    }
    delete [] pChars;
    pChars = x;
    space = n;
}

}

