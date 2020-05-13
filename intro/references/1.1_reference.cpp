#include <iostream>
#define LOG(x) std::cout << x << std::endl;

int main()
{
    int a = 8;
    int& ref = a; //creating a reference variabble "ref" which is infact an alias to variable "a"
    //this is essentially different from the usage of "&" in case of pointer definition

    int* aptr = &a;
    int* rptr = &ref;

    ref = 9;
    LOG(a);
    LOG(ref);
    std::cin.get();
}
