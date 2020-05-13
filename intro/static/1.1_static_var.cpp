/*
 *  1.1_static_var.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 28 Apr 2018 12:31:39 IST
 *  ver    :
 *
 */


#include <iostream>


void counter()
{
    static int s_count{0}; //static variable
    s_count ++;
    std::cout << s_count << " ";

}

int main()
{

    for (int i = 0; i < 5; ++i)
    {
        counter();
    }


    {
        static int s_var{10};
        int* ptr = &s_var;
        std::cout << ptr << std::endl;
    }
    std::cout << "\n " << s_var; //Error: scope is limited to the block in which the variable was defined

    static int s_var{11}; //a different static var
    int* ptr = &s_var;
    std::cout << ptr << std::endl;
    return 0;
}
