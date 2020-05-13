#include <iostream>
#include <bitset>
#include <fstream>



int main()
{
    std::cout << "Hello World" << std::endl;
    // std::cout    : A global const of std::ostream
    // std::ostream : typedef basic_ostream<char> ostream
    // <<           : std::ostream& operator<<(string)
    // endl         : '\n' + flush
    //


    //stream        : A Serial IO interface to external devices:
    //                (file, stdin/stdout, network etc)
    //
    //Random Access Interface vs Serial Interface
    //std::string s("Hello");
    //s[2] = 'y' //Random Access
    //cout[2] //error
    //
    //Some streams do have random access capabilities
    //eg: file stream....
    //
    //
    std::ofstream of("out.txt");
    of << "Hello World" << std::endl;
    of << 123 << std::endl;
    of << 1.2 << std::endl;

    of << std::bitset<8>(14) << std::endl;

}
