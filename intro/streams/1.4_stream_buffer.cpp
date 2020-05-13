#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::cout << "cout << Hello\n";
    std::streambuf* pbuf = std::cout.rdbuf();
    std::ostream newCout(pbuf);
    newCout << "newCout << World\n";
    newCout.width(40);
    newCout.setf(std::ios::showpos);
    newCout << 89 << std::endl;
    std::cout << 89 << std::endl;


    //Redirecting cout to file
    std::ofstream of("log.txt", std::ios::out|std::ios::trunc);
    std::streambuf* coutBuff = std::cout.rdbuf(); //save pointer to cout buffer
    std::cout.rdbuf(of.rdbuf()); //Substitute internal cout buffer with buffer
                                // of of
    std::cout << "This will be written to of";

    std::cout.rdbuf(coutBuff);
    std::cout << "This will be NOT written to of";
}

