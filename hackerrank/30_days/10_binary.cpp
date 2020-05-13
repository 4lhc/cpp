
#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;

std::string ToBinary(int n)
{

    std::string s{};
    do
    {
        s = std::to_string(n%2) + s;
    } while ( n /= 2 );

    return s;
}

int MaxSuccOnes(std::string s)
{

    int max_counter{0}, counter{0};

    for( auto i : s)
    {
        if (i == '1')
        {
            counter++;
            max_counter = (counter>max_counter?counter:max_counter);
            //cout << i << " i = 1; counter=" << counter << " max_counter=" << max_counter <<endl;
        }
        else
        {
            counter = 0;
        }

    }
    return max_counter;
}

int main()
{

    int n{};
    cin >> n;
    std::string ss = ToBinary(n);
    //cout << ss << endl;
    //cout << MaxSuccOnes(ss);
    cout << MaxSuccOnes(ToBinary(n));
    return 0;
}
