/*  
 *  2.1_scope.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 08 Aug 2017 00:50:20 IST
 *  ver    : 
 *   
 */


#include <iostream>


int x{10}; //global scope


int main()
{
    int x{0}; //local scope

    std::cout << "local x: " << x << std::endl;
    std::cout << "glbal x: " << ::x << std::endl; //global scope has no name
    //hence the right hand side of the scope operator is empty

	return 0;
}
