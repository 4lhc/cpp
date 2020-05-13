//  sum_of_two.cpp
//
//  author : Sreejith S
//  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
//  date   : Fri 04 Aug 2017 19:30:56 IST
//  ver    : 

// A program to  find the sum of two numbers


#include <iostream>

int main()
	{
		double num_one, num_two;
		std::cout<<"Enter the first number: ";
		std::cin>>num_one;
		std::cout<<"Enter the second number: ";
		std::cin>>num_two;
		std::cout<<"The sum is "<<num_one + num_two<<"\n";
		return 0;
	}
