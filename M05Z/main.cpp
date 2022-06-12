#include "std_lib_facilities.h"
#include "Points.h"

int main()
{
vector<Point> original_points;
Point point;
for(int i=0; i<7; i++)
{
    cout << "(x,y): " << endl;
    cin>>point;
    original_points.push_back(point);
}

ofstream output;
output.open("mydata.txt");
output << original_points;
output.close();



vector<Point> processed_points;
ifstream input;
input.open("mydata.txt");
while(input >> point)
{
    
    processed_points.push_back(point);
}
cout << processed_points;
cout << "Data from file:" << endl;
cout << processed_points;
cout << "Original data:" << endl;
cout << original_points;
input.close();

if(original_points == processed_points) 
    cout << "Vectors equal!" << endl;
else 
    cout << "Something's wrong!" << endl;
return 0;
}