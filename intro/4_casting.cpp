/*
 *  4_casting.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Fri 04 Aug 2017 21:08:38 IST
 *  ver    :
 *
 */

#include <iostream>
#include <typeinfo>
#include <vector>

class Employee
{
    public:
        double JobsHeldPerYear_v1();
        double JobsHeldPerYear_v2();
        Employee(int years, int jobs)
            :_years_employed{years}, _jobs_held(jobs) {} //constructor

    private:
        int _years_employed;
        int _jobs_held;
};


double Employee::JobsHeldPerYear_v1()
{
    //int operations produce an int. The return value is not accurate here
    return _jobs_held/_years_employed;
}

double Employee::JobsHeldPerYear_v2()
{
    //the first var here is cast as double so that the return value is a double
    return (double) _jobs_held/_years_employed;
}

int main()
{
	int i {10}; //uniform list initialization
	double iaa {10.0001};
	i = iaa; // precision is lost
    //int ix = {0.0}; //narrowing conversion inside {} error
	std::cout << typeid(iaa).name(); //output "d" for double
	std::cout << typeid(i).name(); // output "i" for int
	std::cout << "\n" << i;
	//float
	auto o = 10.0;
	std::cout << typeid(o).name();

	double ratio {3.0/2.0};
	std::cout << "\nratio: " << ratio;


    Employee bob{19, 4};
    std::cout << "\n\njobs per year " << bob.JobsHeldPerYear_v1() << std::endl;
    std::cout << "jobs per year " << bob.JobsHeldPerYear_v2() << std::endl;


    for(int i: std::vector<int> {66, 79, 66})
    {
        std::cout << (char) i;
    }

    for(int i: std::vector<int> {66, 79, 66})
    {
        std::cout << static_cast<char> (i);
    }
    //
	//ch = static_cast<char>(l);




	return 0;
}


