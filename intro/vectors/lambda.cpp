/*
 *  lambda.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Fri 04 May 2018 16:11:23 IST
 *  ver    :
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Fraction
{
    public:
        int num{0}, deno{1};

};

int main()
{
    std::vector<Fraction> f{{1,2}, {3,4}, {5,6}, {6,2}};
    std::vector<std::string> names{"Justin", "Christy", "Reenu", "Navaneetha"};

    std::sort(names.begin(), names.end(), [](std::string &a, std::string &b) {
            return a.size() > b.size();
            });
    for(auto i: names)
    {
        std::cout << i << std::endl;

    }


    std::sort(f.begin(), f.end(), [](Fraction &a, Fraction &b) {
            return a.deno < b.deno;
            });

    for (auto i: f)
    {
        std::cout << i.num << "/" << i.deno << std::endl;
    }

    /*
     * Fraction& sort(a, b) {       }
     * */
    return 0;
}
