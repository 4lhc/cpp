/*  
 *  5_array.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Fri 04 Aug 2017 22:05:29 IST
 *  ver    : 
 *   
 */


#include <iostream>

using namespace std;


int main()
{
	int arrayName[10];
	int arrName[] = { 1, 2, 3, 4, 5};
	int arr_with_zeros[10] = { 1, 2, 3};
	for (int i = 0; i < 10; i++)
	{
		cout << arr_with_zeros[i] << endl;
	}
	int arr[] = {1, 2, 3, 0};
	cout << arr[4] << endl;
	return 0;
}
