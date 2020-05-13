
#include <iostream>
#include <string>


int main()
{
    std::string input_str{};

    std::getline(std::cin, input_str);
    std::cout << "Hello, World." << std::endl;
    std::cout << input_str << std::endl;

	return 0;
}
