#include <iostream>
#include <stdexcept>


int main()
{
    int x;
    std::cout << "X = ";
    try
    {
        std::cin >> x;
    if (x == 0)
    throw std::domain_error("0 not accepted");

    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what();

    }
}
