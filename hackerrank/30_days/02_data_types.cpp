

#include <iostream>
#include <iomanip>



int main()
{
    int i = 4;
    double d = 4.0;
    std::string s = "HackerRank ";


    int i2{};
    double d2{};
    std::string s2{};

    std::cin >> i2 >> d2;
    std::cin.ignore();
    std::getline(std::cin, s2);


    std::cout << i + i2 <<std::endl;
    std::cout << std::fixed << std::setprecision(1) << d + d2 << std::endl;

    std::cout << s << s2 << std::endl;



	return 0;
}
