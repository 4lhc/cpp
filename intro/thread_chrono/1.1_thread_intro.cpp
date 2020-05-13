/*
 *  1.1_thread_intro.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 01 May 2018 15:47:37 IST
 *  ver    :
 *
 */


#include <iostream>
#include <thread>


using namespace std::chrono_literals;
void Loading()
{
    std::cout << "Working";
    for(int i = 0; i < 10; i++)
    {

        std::cout << "." << std::flush;
        std::this_thread::sleep_for(1000ms);
    }
}

void Worker()
{

    for(int i = 0; i < 20; i++)
    {

        std::cout << "*" << std::flush;
        std::this_thread::sleep_for(500ms);
    }

}

int main()
{
    std::thread helper1(Worker);
    std::thread helper2(Loading);

    helper1.join();
    helper2.join();
    std::cin.get();

    return 0;
}
