/*  
 *  11.1_args.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Mon 28 Aug 2017 21:41:34 IST
 *  ver    : 
 *   
 */


#include <iostream>


using std::cout;
using std::cin;
using std::endl;

int main(int argc, char ** argv, char * envp[])
{

    cout << "Number of args = " << argc-1 <<endl;
    for (int i=0; i<argc; i++)
    {
        cout << argv[i] << endl;
        cout << envp[i] << endl;
    }
	return 0;
}
