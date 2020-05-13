/*  
 *  04_classes.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 26 Aug 2017 05:20:04 IST
 *  ver    : 
 *   
 */


#include <iostream>
using std::cin;
using std::cout;

class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        // Add some more code to run some checks on initialAge
        if (initialAge<0)
        {
            cout << "Age is not valid, setting age to 0." << std::endl;
            age = 0;
        }
        else
            age = initialAge;

    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console
        if (age < 13) cout << "You are young." << std::endl;

        else if (age >=13 && age<18 ) cout << "You are a teenager." << std::endl;

        else cout << "You are old." << std::endl;


    }

    void Person::yearPasses(){
        // Increment the age of the person in here
        ++age;

    }



int main()
{
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses();
        }
        p.amIOld();

		cout << '\n';
    }

    return 0;
}
