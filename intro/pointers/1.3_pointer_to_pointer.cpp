#include <iostream>

int main()
{
    int x = 10;
    int* ptr = &x; //take memory address of variable x and storing it in a pointer
    int** p2ptr = &ptr; //pointer to a pointer

    std::cout << "*ptr: " <<*ptr << std::endl; //dereferencing the pointer. Accessing the data
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "*p2ptr: " << *p2ptr << std::endl; //dereferencing the pointer. Accessing the data
    std::cout << "**p2ptr: " << **p2ptr << std::endl; //dereferencing the pointer. Accessing the data
    std::cout << "p2ptr: " << p2ptr << std::endl; //dereferencing the pointer. Accessing the data


    *ptr = 12; //the compiler knows this is an interger and the xact number of
               // bytes it needs
    std::cin.get();
}
