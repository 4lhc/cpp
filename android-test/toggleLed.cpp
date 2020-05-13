#include <iostream>
#include <fstream>
#include <unistd.h>


int main(int argc, char** argv)
{

    int sleepDuration{500}; //ms
    bool ledState;
    int count{100};

    for (int i = 0; i < count; ++i)
    {
        std::fstream fs(argv[1], std::ios::in);
        //fs(filename, mode)
        fs >> ledState;
        ledState = !ledState;
        fs.close();
        fs.open(argv[1], std::ios::out);
        fs << ledState;
        fs.close();

        usleep(sleepDuration*1000);

    }

    return 0;
}
