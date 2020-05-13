#include <iostream>

int main()
{
    int x = 10;
    void* vptr = &x; // a void pointer
    int* ptr = &x; //take memory address of variable x and storing it in a pointer
    std::cout << ptr;
    std::cout << *ptr; //dereferencing the pointer. Accessing the data

    *vptr = 7; //incomplete type: void is not assignable; compiler doesn't know how muchjc

    *ptr = 12; //the compiler knows this is an interger and the xact number of
               // bytes it needs
    std::cin.get();
}
