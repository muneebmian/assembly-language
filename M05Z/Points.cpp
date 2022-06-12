#include "std_lib_facilities.h"
#include "Points.h"

ostream& operator<<(ostream& os, const Point& p)
{
    os<<"("<<p.x<<","<<p.y<<")";
    return os;
}
istream& operator>>(istream& is, Point& p)
{
    char brace,punct,brace2;
    if(!is)

      return is;
    is >> brace >> p.x >> punct >> p.y >> brace2;
    
    return is;
}
bool operator==(const Point& p1, const Point& p2)
{
    if(p1.x == p2.x && p1.y == p2.y) 
        return true;
    else 
        return false;
}
bool operator!=(const Point& p1, const Point& p2)
{
    if(p1.x != p2.x || p1.y != p2.y) 
        return true;
    else 
        return false;
}
ostream& operator<<(ostream& os, const vector<Point> & points)
{
    for(unsigned j=0; j< points.size(); j++)
    {
    os << points.at(j) << endl;
    
    }
    return os;
}
