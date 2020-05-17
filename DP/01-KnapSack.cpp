/*  
 *  01-KnapSack.cpp
 *  Top-Down
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Thu 06 May 2020 16:04:44 IST
 *  ver    : 
 *
 *  Compile: g++ -Wall -Wextra -pedantic -g -std=c++14 -o test 01-KnapSack.cpp
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;

typedef vector<vector<int>> Mat;

int KS(int n, int C, Mat memo, const vector<int>& W, const vector<int>& v)
{
    int result, tmp1, tmp2;
    if (memo[n][C] != -1)
    {
        //already computed and saved in memo
        return memo[n][C];
    }

    if (n==0 || C==0)
    {
        //exhausted capacity
        result = 0;
    }
    else if (W[n] > C)
    {
        //individual wt > Cap remaining
        result = KS(n-1, C, memo, W, v);
    }
    else
    {
        tmp1 = KS(n-1, C, memo, W, v);
        tmp2 = v[n] + KS(n-1, C-W[n], memo, W, v);
        result = std::max(tmp1, tmp2);

    }
    memo[n][C] = result;
    return result;

}

int main()
{
    int n{0}, C{0};
    int input;
    vector<int> v, W;
    cin >> n >> C;
    v.push_back(0);
    for(int i=1; i<=n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    W.push_back(0);
    for(int i=1; i<=n; i++)
    {
        cin >> input;
        W.push_back(input);
    }
    Mat memo(n+1, vector<int>(C+1, -1)); //init nxC matrix with -1


    for(int i=0; i<=n; i++)
    {
        cout << v[i] << " | " << W[i] << std::endl;
    }
    cout << "Result: " << KS(n, C, memo, W, v) << std::endl;

    //printing the top-down table
    for(auto row:memo)
    {
        for(auto col:row)
        {
            cout << col << "    ";
        }
        cout << std::endl;
    }
    return 0;
}
