#include <iostream>
#include <string>


int main()
{
    std::string s1{}, s2{};
    std::cin >> s1 >> s2;

    std::cout << s1.size() << " " <<  s2.size() << std::endl;
    std::cout << s1 + s2 << std::endl;

    char a = s1[0];
    char b = s2[0];

    s1[0] = b;
    s2[0] = a;

    std::cout << s1 << " " << s2 << std::endl;


    return 0;
}

