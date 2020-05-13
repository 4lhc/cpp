

#include <iostream>
#include <algorithm>


int main()
{

    int a[] = {1, 4, 2,  78, 4};
    int *ptr0 = &a[0];
    int *ptr1 = &a[1];

    std::cout << "a :" << a << std::endl; //pointer to the zeroth element
    std::cout << "ptr0 :" << ptr0 << std::endl; //pointer to the zeroth element
    std::cout << "ptr1 :" << ptr1 << std::endl; //pointer to the first element
    std::cout << "ptr0 + 1 :" << ptr0 +1 << std::endl; //pointer to the first element
    std::cout << "a+1 :" << a + 1 << std::endl; //pointer to the first element
    return 0;
}
