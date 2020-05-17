/*
 *  04-fibonacci_DP.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Mon 11 May 2020 01:47:10 IST
 *  ver    :
 *
 *  Compile: g++ -Wall -Wextra -pedantic -g -std=c++14 -o test 04-fibonacci.cpp
 *  g++ ver: (Ubuntu 8.3.0-6ubuntu1) 8.3.0
 *
 *  ./test <<< "6"
 *
 */


#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;


int fibo(int n, vector<int>& memo)
{
    int result{0};
    if (memo[n-1] != -1)
        return memo[n-1];
    if (n<=1)
        result = n;
    else
        result = fibo(n-1, memo) + fibo(n-2, memo);
    memo[n-1] = result;
    return result;
}



int main()
{
    int n{0};
    cin >> n;
    vector<int> memo(n, -1);    //using int sets a limit of fibo(46)
    cout << "Fibo(" << n << ") is " << fibo(n, memo) << std::endl;

    for(auto i:memo)
    {
        cout << i << " ";
    }
    cout << std::endl;
	return 0;
}
