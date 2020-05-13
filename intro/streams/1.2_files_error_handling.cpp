#include <iostream>
#include <fstream>
#include <iomanip>
#include <bitset>


#define LOG(s, x) std::cout << s << ": "  << x << std::endl;

int main()
{
    std::string filename = "out.txt";
    std::string message = "j 2.3 three .";

    {
        std::ofstream of(filename);
        of << message << std::endl;
    }

    {
        int first;
        double second;
        std::string third;
        char fourth;
        std::ifstream ifs(filename);
        ifs >> first >> second >> third >> fourth;
        LOG("first", first);
        LOG("second", second);
        LOG("third", third);
        LOG("fourth", fourth);


    }

    LOG("-", "---------");
    {
        int first;

        std::ifstream ifs(filename);

        ifs >> first;
        LOG("first", first);
        LOG("ifs.rdstate()", std::bitset<4>(ifs.rdstate()) );
        LOG("ios::failbit", std::ios::failbit)

    }
}
