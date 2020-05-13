#include <iostream>

#define PRINT(x) std::cout << x << std::endl;

int a;

int& test()
{
    return a;
}


int main()
{

    test()  = 6;
    PRINT(a);
}
