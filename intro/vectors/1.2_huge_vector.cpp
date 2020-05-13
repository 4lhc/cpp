#include <iostream>
#include <vector>
#include <string>

void eraseEven(std::vector<long> &v)
{
    std::vector<long> eVec;
    std::vector<long>::size_type i = 0;

    while (i != v.size())
    {
        if ( v[i] % 2 == 0 )
            v.erase(v.begin() + i);
        i++;

    }
}
int main(int argc, char** argv)
{

    if(argc == 1)
    {
        std::cout << "Usage: " << argv[0] << " N\n"
                     "N - Number of items in vector\n";
        return 1;
    }
    std::string limit = argv[1];
    long lim = std::stoul(limit);

    std::vector<long> vec(lim);

    for (auto i : vec)
    {
        i = lim;
        lim--;
    }

    std::cout << "Size of vec: " << vec.size() << "\n";
    eraseEven(vec);
    std::cout << "Size of vec: " << vec.size() << "\n";









}
