/*
 *  02-MatrixChainMult.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 09 May 2020 22:23:15 IST
 *  ver    :
 *
 *  compile:
 *  g++ -Wall -Wextra -pedantic -g -std=c++14 -o test 02-MatrixChainMult.cpp
 *
 *  ./test <<<"6 30 35 15 5 10 20 25"
 *
 */


#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

using std::vector;
using std::cout;
using std::cin;
typedef vector<vector<int>> Mat;

int MatrixCost(Mat& memo, vector<int>& d, int i, int j)
{
    if (i==j)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];


    int bestCost = std::numeric_limits<int>::max(); //set to inf in pseudocode
    int cost{0};
    for (int k = i; k < j; k++)
    {
        cost = MatrixCost(memo, d, i, k) + MatrixCost(memo, d, k+1, j)
                                         + d[i-1]*d[k]*d[j];

        if (cost < bestCost)
            bestCost = cost;
    }
    memo[i][j] = bestCost;
    return bestCost;
}



int main()
{

    int n{0}; //dim size
    int input{0};
    vector<int> d;
    cin >> n ;
    for(int i=0; i<=n; i++)
    {
        cin >> input;
        d.push_back(input);
    }

    Mat memo(n+1, vector<int>(n+1, -1)); //init (n+1)x(n+1) matrix with -1
    //n+1 is used for simplicity even though this adds an extra row and col
    //to the beginning of memo


    cout << "n = " << n << std::endl;
    cout << "d = { ";
    for(int i=0; i<=n; i++)
    {
        cout << d[i] << " ";
    }
    cout << "}\nOptimal # of Scalar Multiplications: "
         << MatrixCost(memo, d, 1, n) << std::endl;

    //printing the top-down table
    for(auto row:memo)
    {
        for(auto col:row)
        {
            cout << std::setw(10);
            if (col == -1)
                col = 0;
            cout << col;
        }
        cout << std::endl;
    }
    return 0;
}
