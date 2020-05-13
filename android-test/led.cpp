#include <iostream>
#include <fstream>
#include <bitset>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout << "Usage: " << argv[0] << " FILENAME\n";

        return 1;
    }

    bool ledState;
    std::fstream fs(argv[1], std::ios::in);
    fs >> ledState;
    ledState = !ledState;

    fs.close();
    fs.open(argv[1], std::ios::out | std::ios::trunc);

    fs << ledState;
    fs.close();

    return 0;
}
