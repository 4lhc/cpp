#include <iostream>
#include <cmath>

void Update(int *a,  int *b)
{
    int temp = abs( *a - *b );
    *a += *b;
    *b = temp;
}

int main()
{
    int a{}, b{};
    int *pa = &a, *pb = &b;

    std::cin >> a >> b;

    Update(pa,  pb);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

	return 0;
}
