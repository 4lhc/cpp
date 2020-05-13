
#include <iostream>
#include <algorithm>


int GreatestOfFour(int a, int b, int c, int d)
{

// return max(max(a, b), max(c, d));
   return (a>b?(a>c?(a>d?a:d):(c>d?c:d)):(b>c?(b>d?b:d):(c>d?c:d)));
//nightmare of the third kind

}

int main()
{

    int a, b, c, d;

    std::cin >> a >> b >> c >> d;
    std::cout << GreatestOfFour(a, b, c, d) << std::endl;

	return 0;
}
