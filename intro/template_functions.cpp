/*  
 *  template_functions.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 24 Apr 2018 15:23:10 IST
 *  ver    : 
 *   
 */


#include <iostream>

template <typename T>
void printN(T &var)
{
    std::cout << var << std::endl;
}


int main()
{
    int x = 0;
    int* p = &x;

    char ch = 'c';
    char* ptr = &ch;
    double a = 10.213;
    printN(x);
    printN(a);
    printN(ptr);

	return 0;
}
