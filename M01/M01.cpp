#include "../std_lib_facilities.h"

int main()
{
  string operation;
  double num1;
  double num2;

  cout << ": ";
  cin >> operation;
  cin >> num1;
  cin >> num2;

  if(operation == "+")
  {
    //cout << "+ " << num1 << " " << num2;
    cout << "= " << num1 + num2;

  }
  else if(operation == "-")
  {
    //cout << "- " << num1 << " " << num2;
    cout << "= " << num1 - num2;

  }
  else if(operation == "*")
  {
    //cout << "* " << num1 << " " << num2;
    cout << "= " << num1 * num2;

  }
  else if(operation == "/")
  {
    if(num2 != 0)
    {
      //cout << "/ " << num1 << " " << num2;
      cout << "= " << num1 / num2;
    }
    else
    {
      cout << "cannot divide by zero";
    }

  }


}
