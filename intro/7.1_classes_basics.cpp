/*  
 *  7.1_classes_basics.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sun 06 Aug 2017 18:12:21 IST
 *  ver    : 
 *   
 */


#include <iostream>

//Declaring classes
class Student
{
	public:
		std::string _name;
		std::string _rno;
		bool _sleeping_in_class = true;
};

int main()
{

	int x; //uninitialized
	int y{}; //default initialized
	int z{1}; //initialized with value
	
	//declaration
	Student sj;
	//assign values to the members
	sj._name = "Sreejith";
	sj._rno = "41";
	sj._sleeping_in_class = false;

	//definition
	Student someone{ "Someone Simone", "37", true};

	//default value initialization 
	Student another_one {}; 
	std::cout << someone._name; 
	std::cout << another_one._name; 
	return 0;
}
