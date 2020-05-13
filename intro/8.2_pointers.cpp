/*  
 *  8.2_pointers.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Fri 11 Aug 2017 00:24:57 IST
 *  ver    : 
 *   
 */


#include <iostream>



int main()
{
    int a = 30;
    int *ptr_a = &a;
    std::cout << &a << std::endl;
    std::cout << a << std::endl;
    std::cout << *ptr_a<< std::endl;
    std::cout << ptr_a << std::endl;
    std::cout << &ptr_a << std::endl;
    int *ptr; //unintialized pointer - warning with -Wmaybe-uninitialized
    std::cout << *ptr << std::endl;

    int *p1 = NULL; //NULL pointer
    int *p2 = 0; //NULL pointer
    int *p3{}; //NULL pointer???
    *p1 = a;
    std::cout << "------" << std::endl;
     std::cout << p1 << std::endl;
     std::cout << *p1 << std::endl;
     std::cout << p2 << std::endl;
     std::cout << &p2 << std::endl;
     std::cout << p3 << std::endl;
     std::cout << &p3 << std::endl;

	return 0;
}
