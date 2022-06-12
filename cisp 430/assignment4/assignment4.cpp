#include <iostream>
#include <stack>
#include <string>
using namespace std;

using namespace std;
template <typename Elem> class Stack {
    private:
        void operator =(const Stack&) {}
        // Protect assignment
        Stack(const Stack&) {}
        // Protect copy constructor
    public:
        Stack() {}
            // Default constructor
        virtual  ~Stack() {}
    // Base destructor// Reinitialize the stack.  The user is responsible for// reclaiming the storage used by the stack elements.
        virtual void clear() = 0;// Push an element onto the top of the stack.
        virtual void push(const Elem&) = 0;// Remove and return the element at the top of the stack.
        virtual Elem pop() = 0;// Return a copy of the top element.
        virtual const Elem& topValue() const = 0;// Return the number of elements in the stack.
        virtual int length() const = 0;

};

template <typename Elem> class AStack : public Stack<Elem> {
    private:
    int maxSize;              // Maximum size of stack
        int top;
        // Index for top element
        Elem*listArray;
        // Array holding stack elements
    public:
        AStack(int size =255)
        // Constructor
        {   maxSize = size;
            top = 0;
            listArray = new Elem[size]; }
        ~AStack()
        { delete [] listArray; }
        // Destructor

        void clear() { top = 0; }
         // Reinitialize

        void push(const Elem& it) {
             // Put "it" on stack
             if(top != maxSize) {
             listArray[top++] = it;}
        }

        Elem pop()
        {                // Pop top element
             if(top != 0) {
            return listArray[--top];}
        }

        const Elem& topValue() const
        {     // Return top element
            if(top != 0) {
            return listArray[top-1];}
        }
        int length() const { return top; }  // Return length};
};
bool Balanced(string str)
{
   AStack<char> st(255);
   for(int i=0;i<str.length();i++)
   {
       // if opening bracket
       if(str[i]=='{'||str[i]=='('||str[i]=='[')
       st.push(str[i]);
       else{ //else closing bracket then check if stack is empty then return false
       // otherwise if top of the stack is msatched then popped it out
           if(st.length()<=0) // if stack is empty
           return false;
           char ch=st.topValue();
           if((str[i]==']'&&ch=='[')||(str[i]=='}'&&ch=='{')||(str[i]==')'&&ch=='('))
           st.pop();
           else
           return false;

       }
   }
   return true;
}

int main()
{
      string characters;
      cout << "please enter characters: ";
      cin>>characters;     // take the input as a string

        bool answer = Balanced(characters);       //  this function return true if the expression is valid, otherwise it returns false



        if(answer == true)
                cout<<"true";
        else
                cout<<"false";

    return 0;
}
