#include<iostream>
#include<cstring>
using namespace std;
const int LENGTH = 21;
int main()
{
    char word[]= "in class";
    char *ptr = word;


    return 0;
}

void backwardString(string *ptr)
{
    int fromEnd = LENGTH - 1;
    for(int count = 0 ; count < length ; count++)
    {

        *(ptr + count) = *(ptr + fromEnd);


    }

}

void vowels(char *ptr)
{
    int total = 0;
    for(int count = 0; count < strlen(ptr); count++ )
    {
        toupper(*(ptr + count));
        if(*(ptr + count) == "A" || *(ptr + count) == "E" || *(ptr + count) == "I" || *(ptr + count) == "O" || *(ptr + count) == "U"))
        {
            total += 1;

        }

    cout << total;



    }



}



}
