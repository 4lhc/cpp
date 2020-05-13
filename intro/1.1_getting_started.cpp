/*  
 *  1.1_getting_started.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Mon 07 Aug 2017 20:06:02 IST
 *  ver    : 
 *   
 */


#include <iostream>



int main()
{
    int a{0};
    int b{0};
    std::cout << "Enter two numbers :" << std::endl;
    std::cin >> a >> b;
    if ( b == 0 )
    {
        std::cerr << "ERROR: Division by zero." << std::endl;
        std::clog << "LOG: Error occured during "
                     "another line of log" << a << "/" << b << std::endl;
        return 1;
    }
    else
    {
        std::cout << a << "/" << b << " = " << a/b << std::endl;
        std::clog << "LOG: " << a << "/" << b << std::endl;
    }

	return 0;
}
