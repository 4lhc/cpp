/*
 *  1.2_static_var_in_class.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 28 Apr 2018 12:55:52 IST
 *  ver    :
 *
 */


#include <iostream>
#include <string>
#include <vector>

class Student
{
    private:
        std::string m_name{};
        int m_ID;

    public:
        Student (std::string name)
            :m_name(name)
        {
            static int s_ID = 0;
            m_ID = ++s_ID;

        }
        virtual ~Student () {};
        friend std::ostream& operator<<(std::ostream &os, Student &s)
        {
            os << "Name : " << s.m_name << "\nID : " << s.m_ID << std::endl;
            return os;
        }
};



int main()
{

    std::vector<Student> students;
    students.push_back(Student{"Mike"});
    students.push_back(Student{"Jared"});
    students.push_back(Student{"Monika"});

    for(auto s: students)
    {
        std::cout << s;
    }
    return 0;
}
