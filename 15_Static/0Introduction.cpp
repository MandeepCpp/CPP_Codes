//In C++, a static member function of a class cannot be virtual. 
//Virtual functions are invoked when you have a pointer or reference to an instance of a class. 
//Static functions aren’t tied to the instance of a class but they are tied to the class. 
//C++ doesn’t have pointers-to-class, 
//so there is no scenario in which you could invoke a static function virtually.


// static member functions do not have this pointer. 

// Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration. 

// A static member function can not be declared const, volatile, or const volatile.
// static void fun() const { // compiler error