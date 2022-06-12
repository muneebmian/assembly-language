#include "iostream"
using namespace std;



namespace Vector{

template<class T> class vector {
    int sz;
    T* elem;
    int space;
   
public:
    vector() : sz{0}, elem{nullptr}, space(0){}
    const T& at(int n) const;
    const T& operator[ ](int n) const;

    explicit vector(int n); //: sz{n}, elem{nullptr}, space{n}
    /*{
        for(int i = 0; i<sz;i++) elem[i] = T();
    }*/
    

    vector(const vector&);                      // copy constructor
    vector& operator=(const vector<T>&);           // copy assignment

    vector(vector<T>&&);                           // move constructor
    vector& operator=(vector<T>&&);  
    vector(std::initializer_list<T> lst); 
    //T& operator[](int n){return elem[n];} 
    T& at(int n);			// checked access                                                                                                                     // move assignment


    ~vector()                                   // destructor
    {
        cout << "destructor called!\n";
        delete[ ] elem;
    }
                                // checked access   

    T& operator[](int n);   // unchecked access
    

    int size() const { return sz; }
    int capacity() const { return space; }

    void reserve(int);                          // growth
    void push_back( T d);
    void resize(int);
    T get(int n) const { return elem[n];}
    void set(int n,T v){elem[n]=v;}
};
template<typename T>
vector<T>::vector(int s) : sz{s}, elem{new T[s]}, space{s}
{
    for(int i = 0; i<sz;i++) elem[i] = T();
}
template<typename T>
vector<T>::vector(std::initializer_list<T> lst) :sz{(int)lst.size()}, elem{new T[sz]},space{0}
{
    std::copy(lst.begin(),lst.end(),elem);
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// 
template<typename T>
vector<T>::vector(const vector<T>& a) : sz{a.sz}, elem{new T[a.sz]}, space{a.sz}
{
    for(int i = 0;i<sz;i++) elem[i] = a.elem[i];
    cout << "copy constructor called" << endl;
}

/*template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& a)
{
    cout << "copy assignment called!\n";
    T * p=new T[a.space];  
    space = a.space;             // check if already have enough space
        for (int i = 0; i < a.sz; ++i) p[i] = a.elem[i];
        delete [] elem;
        sz = a.sz;
        elem = p;
        return *this;
 }*/


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// move operations
template<class T> 
vector<T>::vector(vector<T>&& a)
    : sz{a.sz}, elem{a.elem}, space{a.space}
{
    cout << "move constructor called!\n";
    a.sz = 0;
    a.elem = nullptr;
}
template<class T> 
vector<T>& vector<T>::operator=(const vector<T>& a)
{
	if (this==&a) return *this;	// self-assignment, no work needed

	if (a.sz<=space) {		// enough space, no need for new allocation
		for (int i = 0; i<a.sz; ++i) elem[i] = a.elem[i];	// copy elements
		sz = a.sz;
		return *this;
	}

	T* p = new T[a.sz];			// copy and swap
	for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];	
	delete[ ] elem;			
	sz = a.sz;		
	space = a.sz;
	elem = p;
	return *this; 
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// range checking
template<class T> 
T& vector<T>::at(int n)
{
    if (n < 0 || sz < n) throw out_of_range("");
    return elem[n];
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// growth
template<class T> 
void vector<T>::reserve(int newalloc)
	// make the vector have space for newalloc elements
{
	if (newalloc<=space) return;		// never decrease allocation
	T* p = new T[newalloc];	// allocate new space
	for (int i=0; i<sz; ++i) p[i]=elem[i];	// copy old elements
	delete[ ] elem;				// deallocate old space
	elem = p;	
	space = newalloc;		
}


template<class T> 
void vector<T>::push_back(T d)
	// increase vector size by one
	// initialize the new element with d
{
	if (sz==0) 			// no space: grab some
		reserve(8);
	else if (sz==space) 	// no more free space: get more space
		reserve(2*space);
	elem[sz] = d;		// add d at end
	++sz;		// and increase the size (sz is the number of elements)
}


template<class T> 
void vector<T>::resize(int newsize)
	// make the vector have newsize elements
	// initialize each new element with the default value 0.0
{
	reserve(newsize);		// make sure we have sufficient space
	for(int i = sz; i<newsize; ++i) elem[i] = T();	// initialize new elements
	sz = newsize;	
}
struct out_of_range { /* … */ };


template<class T>  T& vector<T>::operator[ ](int n)
{
	return elem[n];
}
template<class T> const T& vector<T>::operator[ ](int n) const 
{
	return elem[n];
}
template<class T>  const T& vector<T>::at (int n) const
{
	if (n<0 || sz<=n) throw out_of_range();
	return elem[n];
}
template<class T> ostream& operator<<(ostream& os, vector<T> v) 
{
    for(unsigned i =0;i< v.size();i++)
    {
        os << v.at(i) << " ";
    }
    return os;
}

}