/*
 *  06_strings.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 26 Aug 2017 05:37:05 IST
 *  ver    :
 *
 */


#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;

int main()
{
    int t{0};
    cin >> t;

    cin.ignore();
    for(int j=0; j < t; ++j)
    {
        std::string str{};
        std::getline(cin, str);
        for (unsigned int i=0; i<str.size(); i+=2)
        {
            cout << str[i];
        }
        cout << " ";

        for (unsigned int i=1; i<str.size(); i+=2)
        {
            cout << str[i];
        }
        cout << endl;
    }

    return 0;
}
