#include "std_lib_facilities.h"
int main()
{
  double meter;
  double num;
  double min = 9999.12;
  double max=-9999.12;
  string unit;
  double sum = 0;
  vector<double>meters;
  
  //cin >> num >> unit;
  while(cin >> num >> unit)
  {
    
    if(unit != "cm" && unit != "m" && unit != "in" && unit != "ft")
    {
      cout << "Invalid unit\n";
      break;
    }
    
    if(unit == "cm")
      {
        meter = num/100.0;

      }
    else if(unit == "in")
        {
          meter = num * 0.0254;
          
        }
    else if(unit == "ft")
          {
            meter = num * 0.3048;

          }
    else if(unit == "m")
    {

      meter = num;
    }
    cout << meter << "m"<< endl;
    if(meter < min)
    {
      min = meter;
      //cout << meter << "m"<< endl;
      cout << "The smallest so far" << endl;
    }
    if(meter>max)
    {
      //cout << meter << "m" << endl;
      max = meter;
      cout << "The largest so far" << endl;
    }

    meters.push_back(meter);
    /*if(meters.size() > 1)
     {
        for (int j = 0; j < meters.size() - 1; j++)
        {
            if (meters.at(j) > meters.at(j+1))
            {
                int temp = meters.at(j);
                meters.at(j) = meters.at(j+1);
                meters.at(j+1) = temp;
                j = -1;
            }
        }
      }*/
      
      
      sum += meter;
      //cout << meter << "m"<< endl;

  }
  sort(meters);
  if(unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
    {cout << "Smallest: " << meters.at(0) << ", Largest: " << meters.at(meters.size()-1) << ", Total: " << sum << endl;
     cout << "values: ";
     for(int j = 0; j < meters.size(); j++)
        {
            

            cout << meters.at(j) << " ";



        }
      }



}
