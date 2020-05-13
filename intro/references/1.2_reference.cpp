#include <iostream>
#define LOG(x) std::cout << x << std::endl;


void incrementByVal(int value)
{
    //a new copy of "a" is created
    value++;
}

void incrementiByPointer(int* ptr)
{
    LOG("Inside incrementiByPointer: ");
    LOG(ptr);
    (*ptr)++;
    LOG(ptr);
    LOG(*ptr);
}

void incrementByReference(int& ref)
{
    ref++;

}


int main()
{
    int a = 8;
    int b = 19;

    //////
    //int& ref = a; //created reference to a
    //int& ref1; //error: is not correct; declaraiotn of reference variable requires an intializer
/*
    LOG(a);
    incrementByal(a);
    LOG(a);
    LOG("Address of a: ");
    LOG(&a);
    incrementiByPointer(&a);
    LOG(a);

  */
    incrementByReference(a);
    LOG(a);
    std::cin.get();
}
