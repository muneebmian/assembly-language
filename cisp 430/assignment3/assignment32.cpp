#include <iostream>

#include <list>
using namespace std;
template <typename Elem> class List {
 // List ADT
    private:
        void operator =(const List&) {}
 // Protect assignment
        List(const List&) {}
 // Protect copy constructor
 public:
    List() {}
 // Default constructor
    virtual  ~List() {}

 // Base destructor// Reinitialize the list.  The client is responsible for
 // reclaiming the storage used by the list elements.

    virtual void clear() = 0;
 // Insert an element at the front of the right partition.
 // Return true if the insert was successful, false otherwise.
    virtual bool insert(const Elem& item) = 0;
 // Append an element at the end of the right partition.
 // Return true if the append was successful, false otherwise.
    virtual bool append(const Elem&) = 0;

 // Remove and return the first element of right partition.
    virtual Elem remove() = 0;

 // Place fence at list start, making left partition empty.
    virtual void movetoStart() = 0;

 // Place fence at list end, making right partition empty.
    virtual void movetoEnd() = 0;

 // Move fence one step left; no change if at beginning.
    virtual void prev() = 0;

 // Move fence one step right; no change if already at end.
    virtual void next() = 0;

 // Return length of left or right partition, respectively.
    virtual int leftLength() const = 0;

    virtual int rightLength() const = 0;// Set fence so that left partition has "pos" elements.
    virtual void movetoPos(int pos) = 0;

 // Return the first element of the right partition.

    virtual const Elem& getValue() const = 0;
};
template <class Elem>
// Defines a template derived class MyList derived from abstract class List
class MyList : public List<Elem>
{
// Template type array
Elem *arr;
// To store size of the array
int size;
// To point to current location
int current;
// To point to end location
int end;
public:
// Default constructor definition
MyList()
{
end = size = current = 0;
}// End of default constructor

// Parameterized constructor to allocate array size
MyList(int no)
{
// Allocates array of size no
arr = new Elem[no];
// Sets the size to no
size = no;
// Current and end points to 0
current = end = 0;
}// End of parameterized constructor

// Clear contents from the list, to make it empty
virtual void clear() const
{
    // Delete the array
    delete arr;
    // Reset the array to null
    arr = NULL;
    // Reset current, end and size to 0
    end = size = current = 0;
}// End of function

// Insert an element at the current location
// item: The element to be inserted
bool insert(const Elem&item)
{
    // Checks if current is equals to size minus one then display error message
    if(current == size - 1)
    cout<<"\n ERROR: Overflow.";
    // Otherwise insert the item
    else
    {
    // Assigns the item at the current index and increase the current counter by one
    arr[current++] = item;
    // Assigns the current counter to end counter
    end = current;
    }// End of else
    }// End of function

// Append an element at the end of the list
// item: The element to be appended
virtual bool append(const Elem& item)
{
    // Checks if current is equals to size minus one then display error message
    if(current == size - 1)
    cout<<"\n ERROR: Overflow.";
    // Otherwise append the item at the end
    else
    {
    // Assigns the item at the end and increase the end counter by one
    arr[end++] = item;
    // Assigns the end counter to current counter
    current = end;
    }// End of else
    }// End of function

    // Remove and return the current element
    // Return: the element that was removed
    Elem remove()
    {
    // Decrease the end by one
    end--;
    // Returns the current index position data and decrease the current index by one
    return arr[current--];
    }// End of function

// Set the current position to the start of the list
virtual void moveToStart() const
{
    current = 0;
}// End of function

// Set the current position to the end of the list
virtual void moveToEnd() const
{
// Assigns end minus one to current
    current = end - 1;
}// End of function

// Move the current position one step left.
// No change if already at the beginning
virtual void prev()
{
// Checks if current index is not zero then decrease the current index by one
    if(current != 0)
    current--;
}// End of function

// Move the current position to one step right.
// No change if already at the end
virtual void next()
{
    // Checks if current index is not size minus one then increase the current index by one
    if(current != size - 1)
    current++;
}// End of function

// Return: The number of elements in the list
virtual int length() const
{
return end;
}// End of function

// Return: The position of the current element.
int currPos() const
{
return current;
}// End of function

// Set the current position.
// Pos: The position to make current
void moveToPos(int pos) const
{
// Checks if parameter position is greater than zero and less than the size
// then assigns the parameter pos to current index
if(pos >= 0 && pos < size)
current = pos;
// Otherwise display error message
else
cout<<"\n ERROR: Invalid position.";
}// End of function

// Return: The current elements
const Elem& getValue() const
{
// Returns the current index position value
return arr[current];
}// End of function
};// End of derived class MyList


int main ()

{
    list <int> ll= {2,23,15,5,9};
    cout << "mylist before removal contains:";
    for (list<int>::iterator it=ll.begin(); it!=ll.end(); ++it)
        cout << ' ' << *it;

cout << '\n';

ll.swap(15);

cout << "mylist after removal contains:";

for (list<int>::iterator it=ll.begin(); it!=ll.end(); ++it)

cout << ' ' << *it;



return 0;

}
