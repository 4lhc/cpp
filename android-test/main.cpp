#include "helloWorld.h"


int main(int argc, char** argv)
{
    helloWorld();
    std::cout << "No. of arguments: " << argc << std::endl;
    std::cout << "Arg0 : " << argv[0] << std::endl;
    std::cout << "Arg1 : " << argv[1] << std::endl;
    return 0;
}
