/*
 *  9.1_operator_overload.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Fri 11 Aug 2017 16:12:40 IST
 *  ver    :
 *
 */
//http://faculty.cs.niu.edu/~mcmahon/CS241/Notes/arithmetic.html

#include <iostream>
#include <stdexcept>
#include <cmath>

class Rational
{
    friend Rational operator*(const int &lhs, const Rational &rhs);
    friend Rational operator*(const Rational &lhs, const Rational &rhs);
    friend Rational operator+(const Rational &lhs, const Rational &rhs);
    friend Rational operator-(const Rational &lhs, const Rational &rhs);
    friend Rational operator/(const Rational &lhs, const Rational &rhs);

    private:
    int _n{1};
    int _d{1};

    public:
    Rational(int num, int din)
    {
        if (din == 0)
            throw std::invalid_argument("Not a rational number.");
        if (num == 0)
            din = 1; //way to store zero without throwing exception

        int sign = (din<0?-1:1); // Carry over -ve sign to the numerator
        _n = sign*num;
        _d = sign*din;
    }

    ~Rational() {}

    void Display()
    {
        if ( _d == 1)
            std::cout << _n <<  std::endl;
        else
            std::cout << _n << "/" << _d << std::endl;
    }

    void LowestForm()
    {
        int min = (_n<_d?_n:_d);
        for(int i=1; i<=abs(min); i++)
        {
            if ( _n%i == 0 && _d%i == 0 )
            {
                _n /= i;
                _d /= i;
            }
        }

    }


};

Rational operator*(const int &lhs, const Rational &rhs)
{
    int num, din;
    num = lhs * rhs._n;
    din = rhs._d;

    Rational result(num, din);
    return result;
}

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    int num, din;
    num = lhs._n * rhs._n;
    din = lhs._d * rhs._d;

    Rational result(num, din);
    return result;
}


Rational operator/(const Rational &lhs, const Rational &rhs)
{
    int num, din;
    num = lhs._n * rhs._d;
    din = lhs._d * rhs._n;

    Rational result(num, din);
    return result;
}


Rational operator+(const Rational &lhs, const Rational &rhs)
{
    int num, din;
    num = lhs._n * rhs._d + rhs._n * lhs._d;
    din = lhs._d + rhs._d;

    Rational result(num, din);
    return result;
}


Rational operator-(const Rational &lhs, const Rational &rhs)
{
    int num, din;
    num = lhs._n * rhs._d - rhs._n * lhs._d;
    din = lhs._d * rhs._d;

    Rational result(num, din);
    return result;
}


int main()
{
    Rational a(1, 3);
    a.Display();
    Rational b(2, 3);
    b.Display();

    Rational x = a - b;
    x.LowestForm();
    x.Display();

    Rational l(222, 424);
    l.LowestForm();
    l.Display();

    Rational c = x / l;
    c.Display();

    Rational z(100, -1);
    z.Display();

    Rational sc = 2*a-b;
    sc.Display();


    try{
        Rational(3, 0); //q=0
    }
    catch(const std::invalid_argument &error)
    {
        std::cerr << error.what() <<  "\nq=0\n";
    }

    Rational(4, 0); //q=0

    return 0;
}
