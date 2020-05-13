

#include <iostream>



int main()
{
    int ar[1000];
    int n{};

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> ar[i];
    }
    for (int i = n-1; i >= 0; i--)
    {
        std::cout << ar[i] << " ";
    }

	return 0;
}
