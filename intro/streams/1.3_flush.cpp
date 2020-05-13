#include <iostream>
#include <fstream>

#include <unistd.h>


int main()
{
    int sleep_dur = 500; //ms
    std::cout << "without flush: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << " ";
        usleep(sleep_dur*1000);
    }
    std::cout << std::endl;

    std::cout << "with flush: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << i << " " << std::flush;
        usleep(sleep_dur*1000);
    }
    std::cout << std::endl;



    return 0;

}
