/*
 *  9.2_rational_numbers_v2.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Fri 18 Aug 2017 10:39:09 IST
 *  ver    :
 *
 */


#include <iostream>
#include <stdexcept>

class Rational
{
    public:
        //ctors
        Rational();
        Rational(int num);
        Rational(int num, int den);
        ~Rational(){};
        //operator overloading
        Rational& operator+=(const Rational& rhs);
        Rational& operator*=(const Rational& rhs);
        Rational& operator-=(const Rational& rhs);
        Rational& operator/=(const Rational& rhs);
        Rational operator-() const ; //unary minus
        Rational& operator++(); //prefix increment
        Rational operator++(int unused); //postfix increment
        bool operator<(const Rational& rhs);
        bool operator==(const Rational& rhs);
        operator double() const; //implicit user defined conversion
        //Friends
        friend Rational operator+(Rational lhs, const Rational& rhs);
        friend Rational operator-(Rational lhs, const Rational& rhs);
        friend Rational operator*(Rational lhs, const Rational& rhs);
        friend Rational operator*(int lhs, const Rational& rhs);
        friend Rational operator/(Rational lhs, const Rational& rhs);

        friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);
        //members

    private:
        int numerator{0};
        int denominator{1};
        void LowestForm();
};


//Constructors definition
Rational::Rational()
    // numerator(0)/denominator(1)
{}

Rational::Rational(int num)
    : numerator(num), denominator(1)
{}

Rational::Rational(int num, int den)
    : numerator(num), denominator(den)
{
    LowestForm();
}


//Operator overloading definition
Rational& Rational::operator+=(const Rational& rhs)
{
    // f1 += f2
    // f1.operator+=(f2)
    //a/b + c/d = (a*d + b*c)/(b*d)
    int a = numerator;
    int b = denominator;
    int c = rhs.numerator;
    int d = rhs.denominator;

    numerator = (a*d + b*c);
    denominator = (b*d);

    LowestForm();
    return *this;
}

//Friend
Rational operator+(Rational lhs, const Rational& rhs)
{
    // f3 = f1 + f2
    return lhs += rhs;
}

Rational& Rational::operator*=(const Rational& rhs)
{
    // f1 *= f2
    // f1.operator*=(f2)
    //a/b * c/d = (a*c)/(b*d)
    int a = numerator;
    int b = denominator;
    int c = rhs.numerator;
    int d = rhs.denominator;

    numerator = (a*c);
    denominator = (b*d);

    LowestForm();
    return *this;
}

//Friend
Rational operator*(Rational lhs, const Rational& rhs)
{
    // f3 = f1 * f2
    return lhs *= rhs;
}

Rational operator*(int lhs, const Rational& rhs)
{

    // f3 = i * f1
    return Rational(lhs) *= rhs;
}



Rational& Rational::operator/=(const Rational& rhs)
{
    // f1 /= f2
    // f1.operator/=(f2)
    //(a/b) / (c/d) = (a*d)/(b*c)
    int a = numerator;
    int b = denominator;
    int c = rhs.numerator;
    int d = rhs.denominator;

    numerator = (a*d);
    denominator = (b*c);

    LowestForm();

    return *this;
}

//Friend
Rational operator/(Rational lhs, const Rational& rhs)
{
    // f3 = f1 / f2
    return lhs /= rhs;
}

Rational Rational::operator-() const
{
    // unary minus
    // f1 = -f2
    Rational r(-numerator, denominator);
    return r;
}

Rational& Rational::operator-=(const Rational& rhs)
{
    // f1 -= f2
    // f1.operator-=(f2)
    return *this += -rhs;
}

Rational operator-(Rational lhs, const Rational& rhs)
{
    return lhs -= rhs;
}


Rational& Rational::operator++()
{
    //prefix
    //a/b + 1 = (a+b)/b
    numerator += denominator;
    return *this;

}

Rational Rational::operator++(int unused)
{

    //post increment
    Rational r(*this); //using copy ctor
    //++*this; //increment with prefix ++
    this->operator++();

    return r; //return unincremented value
}

bool Rational::operator<(const Rational& rhs)
{

    //this method has the caveat of being inaccurate due to accuracy of double
    //probably wouldn't be an issue in this case as it is always in the lowest form
    double left = static_cast<double>(numerator)/denominator;
    double right = static_cast<double>(rhs.numerator)/rhs.denominator;


    return left < right;
}

bool Rational::operator==(const Rational& rhs)
{
    // a/b == c/d ==> a*d = b*c //the issue here is that this can cause overdlow

    //but since the fractions are in lowest form, we just need to check the two parts
    //
    return (numerator == rhs.numerator && denominator == rhs.denominator);
}

Rational::operator double() const
{

    return static_cast<double>(numerator)/denominator;
}


std::ostream& operator<<(std::ostream& os, const Rational& rhs)
{

    if (rhs.denominator == 1)
        os << rhs.numerator;
    else
        os << rhs.numerator << "/" << rhs.denominator;
    return os;

}

void Rational::LowestForm()
{
    //check division by zero and reduce to lowest form
    //adjust negative sign
    if (denominator == 0)
    {
        throw std::invalid_argument("Invalid denominator: q=0");
    }

    if (numerator == 0)
    {
        denominator = 1;
    }
    else
    {

    int min = (numerator<denominator?numerator:denominator);
    int max = (numerator>denominator?numerator:denominator);


    int gcd{min};
    //calculating GCD
    while (max%min != 0)
    {
        //set remainedr to the possible new gcd
        gcd = max%min;
        max = min;
        min = gcd;
    }

    numerator /= gcd;
    denominator /= gcd;

    }



    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }

}

int main()
{
    Rational r1(-4, 8);
    Rational r2(-1, -3);
    Rational r3(0, 1);
    std::cout << r1 << " + " << r2 << " = " << r1 + r2 << std::endl;
    std::cout << r1 << " + " << r3 << " = " << r1 + r3 << std::endl;
    std::cout << "++r1 " << ++r1 << std::endl;
    std::cout << r1 << " / " << r2 << " = " << r1 / r2 << std::endl;

    std::cout << (r1==r1) << std::endl;

    for(Rational r(1,2), limit(4); r<limit; ++r)
    {
        double rd = r; //sets rd to double of r
        std::cout << r << " = " << rd << std::endl;
        //std::cout << r << " = " << (double)r << std::endl; //also correct
    }
	return 0;
}
