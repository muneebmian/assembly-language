#include <iostream>
#include <list>

using namespace std;

template <typename Elem> class List {
 // List ADT
    private:
        int maxSize;
        int listSize;
        int fence;
        Elem* listArray;

 //
 // Protect copy constructor
 public:
    List(int size = 5) {
        maxSize = size;
        listSize = fence = 0;
        listArray = new Elem[maxSize];
    }
 // Default constructor


 // Base destructor// Reinitialize the list.  The client is responsible for
 // reclaiming the storage used by the list elements.


 // Insert an element at the front of the right partition.
 // Return true if the insert was successful, false otherwise.
    virtual bool insert(const Elem& item)
    {
        if(listSize < maxSize)
        {
            for(int i =listSize; i > fence;i--)
            {
                listArray[i]= listArray[i-1];
            }
            listArray[fence] = item;
            listSize++;
            return true;
        }
        return false;
    }
 // Append an element at the end of the right partition.
 // Return true if the append was successful, false otherwise.
    virtual bool append(const Elem& item)
    {
        if(listSize < maxSize)
        {

            listArray[listSize++] = item;
            return true;
        }
        return false;
    }

 // Remove and return the first element of right partition.
    virtual Elem remove()
    {
        Elem it = listArray[fence];
        for(int i = fence;i<listSize-1;i++)
        {
            listArray[i]= listArray[i+1];
        }
        listSize--;
        return it;
    }

 // Place fence at list start, making left partition empty.
    virtual void movetoStart() {fence = 0;}

 // Place fence at list end, making right partition empty.
    virtual void movetoEnd() {fence = listSize;}

 // Move fence one step left; no change if at beginning.
    virtual void prev() {if(fence != 0) fence--;}

 // Move fence one step right; no change if already at end.
    virtual void next() {if(fence < listSize) fence++;}

 // Return length of left or right partition, respectively.
    virtual int leftLength() const {return fence;}

    virtual int rightLength() const {return listSize - fence;}// Set fence so that left partition has "pos" elements.
    virtual void movetoPos(int pos){};

 // Return the first element of the right partition.

    virtual const Elem& getValue() const{return listArray[fence];}
    virtual void display()
    {
        cout << "The list contains; " << endl;
        for(int i = 0; i < listSize;i++)
        {
            if(i == listSize-1)
            {
                cout<< listArray[i];
            }
            else
            {
                cout << listArray[i] << ", ";
            }
        }
        cout << " > " << endl;
    }
    virtual void swap()
    {
        int temp = listArray[fence];
        if(fence == listSize){
            int temp = listArray[fence-1];
            listArray[fence-1]= listArray[0];
            listArray[0] = temp;
        }
        else
        {
            listArray[fence] = listArray[fence+1];
            listArray[fence+1] = temp;
        }


    }

};



int main ()

{
    List<int> ll;
    ll.insert(2);
    ll.append(23);
    ll.append(15);
    ll.append(5);
    ll.append(9);
    // cout << "mylist before removal contains:" << endl;
    ll.display();
    ll.next();
    ll.next();
    ll.remove();
    ll.display();


   // cout << "mylist after removal contains:";
    ll.movetoEnd();
    ll.swap();
    ll.display();




return 0;

}
