#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>

class Student
{
    public:
        std::string name;
        int marks;
        void printname()
        {
            std::cout << name << std::endl;
        }
};

int main()
{

    std::map<std::string, int> marks = {
        {"Reenu", 12},
        {"Justin", 12},
        {"Christy", 12 }
    };
    marks["sreejith"] = 12;
    //std::cout << marks.at("reenu") << std::endl; //throws an exception

    for ( auto it = marks.begin(); it != marks.end(); it++)
    {
        std::cout << it->first << it->second <<  std::endl;

    }

    Student s1{"Reenu", 12};
    Student* ptr = &s1;

    ptr->printname();


}
