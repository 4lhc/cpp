/*  
 *  3_area_of_circle.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Fri 04 Aug 2017 19:47:53 IST
 *  ver    : 
 *   
 */
#include <iostream>

int main()
{
	double radius;
	const double PI{3.14159};
	std::cout<<"radius = """;
	std::cin>>radius;
	std::cout<<"Area = "<<PI*radius*radius<<"\n";
	return 0;
}

	
