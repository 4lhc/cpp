/*
 *  5.4_enum.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 05 Aug 2017 07:15:48 IST
 *  ver    :
 *
 */

#include <iostream>

using namespace std;


int main()
{
    //enum Day { Sun, Mon, Tue, Wed, Thu, Fri, Sat };
    enum Day { Sun=10, Mon=20, Tue, Wed, Thu, Fri, Sat };
	//enum Day { Sun=10, Mon=20, Tue, Wed, Thu='T', Fri, Sat };
	Day  today;
	today = Thu;
	cout << "today:" << today << endl; //will out put 4, 23 & 84 resp.

	return 0;
}
