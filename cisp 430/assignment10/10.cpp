#include <iostream>

using namespace std;

void Sort(int *scores, int sizea){
       int i, j;
       int temp;

       for (i = 0; i < sizea - 1; i++) {


           for (j = 0; j < sizea - i - 1; j++)

               if (*(scores +j) >*(scores +j+1)) {

                   temp = *(scores +j);
                   *(scores +j) = *(scores +j+1);
                   *(scores +j+1) = temp;
               }

       }

}

void printArray(int *arrayPointer,int size){
    for(int i=0;i<size;i++)
        cout<<*(arrayPointer+i)<<" ";
    cout << endl;
}

double average(int *arrayPointer,int size){
    double sum=0;
    for(int i=0;i<size;i++)
        sum = sum+*(arrayPointer+i);

    return sum/size;
}

int main()
{
    int size;
    int *arrayPointer;

    cout <<"Enter size: ";
    cin >>size;

    arrayPointer=new int[size];
    cout <<"Enter "<<size<<" elements: ";
    for(int i=0;i<size;i++){
        cin >>*(arrayPointer+i);
        while(*(arrayPointer+i) < 0)
        {
            cout << "Enter positive number." << endl;
            cin >> *(arrayPointer+i);
        }
    }
    cout <<"Orignal Array: "<< endl;

    printArray(arrayPointer,size);
    Sort(arrayPointer,size);
    cout <<"Sorted Array: "<< endl;

    printArray(arrayPointer,size);
    cout <<"Average: "<<average(arrayPointer,size);


    return 0;
}
