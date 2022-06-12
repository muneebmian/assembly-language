#include <iostream>
using namespace std;

int convertBinaryToDecimal();
void convertDecimalToHex();
void askUser();
void display();

char storeHexNumber[100];
size_t counter = 0;

///*********************************///

int convertBinaryToDecimal(){

  int i = 1, j = 0, remainder, decimal = 0, binaryNumber;
	cout << "\nPlease Input Up to 8-or-less-bits binary sequences\n";

	cout << "Input a binary number: ";
	cin>> binaryNumber;
  while (binaryNumber > 0)
  {
   remainder = binaryNumber % 2;
   binaryNumber = binaryNumber / 10;
   decimal = decimal + remainder * i;
   i = i * 2;
   //cout << decimal << " ";
   //cout << "remainder " << remainder << " ";
  }

  return decimal;
}

void convertDecimalToHex(){

  int decimal = convertBinaryToDecimal();
  int remainder;


  while(decimal != 0){
    remainder = decimal % 16;
    decimal /= 16;

    if(remainder < 10){
      storeHexNumber[counter++] = remainder + 48; /// added according to ASCII character digit conversion.
    }
    else{
      storeHexNumber[counter++] = remainder + 55; /// added according to ASCII character digit conversion.
    }

  }

  display();

}

void askUser(){
  char input;

  do{
    if(input != 'q'){
      convertDecimalToHex();
      cout << "\nTo Stop enter q ?";
      cin >> input;
    }
    else{
      break;
    }

  }while(input != 'q');
  cout << "\nRestart The Program...\n";
}

void display(){

  cout<<"The hexadecimal value: ";

  for(int j = counter-1; j >= 0; j--){

    cout << storeHexNumber[j];
  }

  cout << endl;
  counter = 0; /// empty array set the counter back to 0 after each display.
}

int main(){ askUser(); return 0;}
