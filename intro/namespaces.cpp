#include <iostream>
#include <string>

namespace reenu
{
    void printName()
    {
        std::cout << "My name is Reenu\n";
    }

}

namespace christy
{
    void printName()
    {
        std::cout << "My name is Christy\n";
    }
}

int main()
{
    std::cout << "Hello World!" << std::endl;
    christy::printName();
}

