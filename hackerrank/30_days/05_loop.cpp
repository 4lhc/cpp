
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{


    int n{0};
    cin >> n;
    for(int i=1; i<=10; i++)
    {
        cout << n << " x " << i << " = " << n*i << endl;
    }
	return 0;
}
