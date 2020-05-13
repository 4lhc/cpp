/*  
 *  6.conditional_ternary.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 05 Aug 2017 22:41:28 IST
 *  ver    : 
 *   
 */


#include <iostream>



int main()
{
	int a {10}, b {20};
	int max = (a>b?a:b);
	int min = (a<b?a:b);
	std::cout << "max: " << max << std::endl;
	std::cout << "min: " << min << std::endl;

	// change greater number
	(a < b ? a:b) = max;
	std::cout << "a, b = " << a << ", " << b << std::endl;

	return 0;
}
