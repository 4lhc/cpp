/*  
 *  5.3.1_union.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 05 Aug 2017 07:06:10 IST
 *  ver    : 
 *   
 */


#include <iostream>

using namespace std;

//union is similar to struct, but by writing a memebr, all other members becomes epmpty
union SomeOne {
	int var1;
	double var2;
}some_one {10};

void PrintSomeone(SomeOne &s1)
{
	cout << "some_one.var1 = " << s1.var1 << endl;
	cout << "some_one.var2 = " << s1.var2 << endl;
}

int main()
{
    PrintSomeone(some_one);
    some_one.var2 = 3.14;
    some_one.var1 = 20;
    PrintSomeone(some_one);
    //how to assign second memeber of a union
    //some_one = {.var1 = {40.0}};
	return 0;
}
