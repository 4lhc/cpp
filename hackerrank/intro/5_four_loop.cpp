#include <iostream>
#include <vector>
#include <string>



int main()
{
    std::vector<std::string> d_list{"one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine", "odd", "even"};

    int a{}, b{};
    std::cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        std::cout << (i<=9?d_list[i-1]:(i%2==0?d_list[10]:d_list[9])) << std::endl;
    }
        //ternary xD

	return 0;
}
