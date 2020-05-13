/*  
 *  5.1_strings.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Fri 04 Aug 2017 22:22:58 IST
 *  ver    : 
 *   
 */

#include <iostream>
using namespace std;
int main()

{
	//don't forget the \0 (null) character
	//c style
	char isAString[6] = { 'H', 'E', 'L', 'L', 'O', '\0'};
	char isNotAString[5] = { 'H', 'E', 'L', 'L', 'O'};
	cout << isAString << endl;
	cout << isNotAString << endl;
	
	//inclusion of null character 
	//in the ex below
	char anotherString[7] = "Hello!";
	char yetanotherStr[] = "This is my goal!";
	cout << anotherString << endl;
	cout << yetanotherStr << endl;

	//using string class
	string myString = "This is better!";
	//if the "using" directive was absent
	std::string my_other_string = "MS cpp any good?!";
	cout << myString << endl;
	cout << my_other_string << endl;
	



	return 0;
}
