/*  
 *  03_cond.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 26 Aug 2017 05:10:36 IST
 *  ver    : 
 *   
 */


#include <iostream>



int main()
{

    int n{};
    std::cin >> n;
    if (n%2 == 1) std::cout << "Weird" << std::endl;
    else
{
    if (n>20) std::cout << "Not Weird" << std::endl;
    else if (n>=2 && n<=5) std::cout << "Not Weird" << std::endl;
    else std::cout << "Weird" << std::endl;
}
	return 0;
}
