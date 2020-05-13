/*  
 *  07_array_vec.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 26 Aug 2017 05:52:10 IST
 *  ver    : 
 *   
 */


#include <iostream>
#include <vector>


using std::cout;
using std::cin;
using std::endl;

int main()
{
    int n{};
    cin >> n;
    std::vector<int> vec(0);

    for(int i = 0; i < n; i++)
    {
        int input{};
        cin >> input;
        vec.push_back(input);
    }

    for(auto rit = vec.rbegin(); rit != vec.rend(); rit++)
    {
        cout << *rit << " ";
    }

    cout <<endl;
    //method 2 - creating a reverse vector
    std::vector<int> rvec(vec.rbegin(), vec.rend());
    for (auto i : rvec) cout << i << " ";
    cout <<endl;

	return 0;
}
