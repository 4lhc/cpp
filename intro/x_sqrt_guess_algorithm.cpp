/*  
 *  x_sqrt_guess_algorithm.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sun 03 Sep 2017 17:18:30 IST
 *  ver    : 
 *   
 */


#include <iostream>
#include <ctime>


using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv)
{

    double sqr{}, guess{};
    const double epsilon{0.002};

    cout << "Enter square: ";
    cin >> sqr;
    cout << "Enter guess: ";
    cin >> guess;

    while(abs(guess*guess - sqr) > epsilon)
        {
            cout << guess << " * " << guess << " != " << sqr << endl;
            guess = (guess+sqr/guess)/2;
        }

    cout << guess << " * " << guess << " == " << sqr << endl;





	return 0;
}
