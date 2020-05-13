/*  
 *  7.functions.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 05 Aug 2017 23:42:58 IST
 *  ver    : 
 *   
 */


#include <iostream>

int Sum(int a, int b)
{
	return a+b;
}

//overloading
int Sum(int a, int b, int c)
{
	return a+b+c;
}

//inline function
inline int Max(int a, int b)
{
	return (a>b?a:b);
}

int main()
{

	std::cout << "10 + 20 = " << Sum(10,  20) << std::endl;
	std::cout << "10 + 20 +30 = " << Sum(10,  20, 30) << std::endl;
	std::cout << "max(10, 20) = " << Max(10, 20) << std::endl;

	return 0;
}
