/*  
 *  5.3_union.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 05 Aug 2017 06:53:11 IST
 *  ver    : 
 *   
 */

#include <iostream>

using namespace std;

union PhoneNumber {
	char ph_type_1[11];
	char ph_type_2[6];
	int ph_type_3;
};

void PrintNum(PhoneNumber my_phone_num)
{
	cout << "ph_type_1 :" << my_phone_num.ph_type_1 << endl;
	cout << "ph_type_3 :" << my_phone_num.ph_type_2 << endl;
	cout << "ph_type_3 :" << my_phone_num.ph_type_3 << endl;
}

int main()
{

	PhoneNumber my_phone_num;
	my_phone_num.ph_type_1 = {"9809504721"};
	PrintNum(my_phone_num);
	my_phone_num.ph_type_2 = {"55555"};
	PrintNum(my_phone_num);
	my_phone_num.ph_type_3 = {504721};
	PrintNum(my_phone_num);
	return 0;
}
