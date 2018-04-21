#include <iostream>
#include <sstream>

class Fraction
{
protected:
    int numerator{0};
    int denominator{1};

public :
    Fraction(const int &n, const int &d);
    void printFraction(); // only prototypes here
    void inverse();
    friend int num(const Fraction &f);
    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
    friend std::ostream& operator<<(std::ostream &os, Fraction &f);

};

Fraction::Fraction (const int &n, const int &d)
{
    numerator = n;
    denominator = d;
}

void Fraction::printFraction()
{
    std::cout << numerator << "/" << denominator;
}

void Fraction::inverse()
{
    int temp{numerator};
    numerator = denominator;
    denominator = temp;
}


int num(const Fraction &f)
{
    return f.numerator;
}

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    Fraction f3(1, 1);
    // a/b + c/d = (ad + bc)/bd
    f3.numerator = ( f1.numerator*f2.denominator + f1.denominator*f2.numerator);
    f3.denominator = (f1.denominator*f2.denominator);
    return f3;
}

std::ostream& operator<<(std::ostream &os, Fraction &f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

int main()
{

    Fraction f1(2, 3);
    Fraction f2(1, 3);
    f1.inverse();

    std::cout << f1 << std::endl;

    num(f1); //return numerator This is not a member function

    Fraction f3 = f1 + f2;

    std::cout << f3 << std::endl;

    return 0;
}
