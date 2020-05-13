

#include <iostream>
#include <vector>
#include <string>



int main()
{
    std::vector<std::string> d_list{"one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine", "Greater than 9"};

    int n{};
    std::cin >> n;

    std::cout << (n>9?d_list[9]:d_list[n-1]) << std::endl;


	return 0;
}
