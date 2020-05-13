

#include <iostream>
#include <iomanip>



int main()
{

    int a{};
    long b{};
    char c{};
    float d{};
    double e{};

    std::cin >> a >> b >> c >> d >> e;
    //std::cout << std::setw(10) << std::setfill('x') << a;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(3) << d << std::endl;
    std::cout << std::setprecision(9) << e << std::endl;


	return 0;
}
