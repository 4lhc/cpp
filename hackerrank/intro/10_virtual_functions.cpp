

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

const int NO_OF_SUBJECTS = 6;
int G_PROF_COUNT{0};
int G_STUD_COUNT{0};

class Person
{
    private:
        std::string _name{};
        short int _age{};
    protected:
        int _cur_id{};
    public:
        Person();
        ~Person(){}
        virtual void getdata();
        virtual void putdata();

};

class Professor: public Person
{

    private:
        int _publications{};
    public:
        Professor();
        ~Professor(){}
        virtual void getdata();
        virtual void putdata();

};

class Student: public Person
{

    private:
        int _marks[NO_OF_SUBJECTS];
    public:
        Student();
        ~Student(){}
        virtual void getdata();
        virtual void putdata();
        int SumOfMarks();

};


////////////////////Implement Person members////////////////////
Person::Person()
{}


void Person::getdata()
{
    std::cin >> _name >> _age;
}

void Person::putdata()
{
    std::cout << _name << " " << _age << " ";

    }


////////////////////Implement Professor members////////////////////
Professor::Professor()
{

    _cur_id = ++G_PROF_COUNT;
}


void Professor::getdata()
{
    Person::getdata();
    std::cin >> _publications;
}

void Professor::putdata()
{
    Person::putdata();
    std::cout << _publications << " " << _cur_id << std::endl;

}

////////////////////Implement Student members////////////////////

Student::Student()
{

    _cur_id = ++G_STUD_COUNT;

}

void Student::getdata()
{
    Person::getdata();
    for(int i = 0; i < NO_OF_SUBJECTS; i++)
    {
        std::cin >> _marks[i];
    }

}

void Student::putdata()
{
    Person::putdata();
    std::cout << SumOfMarks() << " " << _cur_id << std::endl;
}


int Student::SumOfMarks()
{
    int sum{0};
    for(int i = 0; i < NO_OF_SUBJECTS; i++)
    {
        sum += _marks[i];
    }
    return sum;
}

////////////////////Main////////////////////

int main(){

    int n, val;
    std::cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        std::cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
