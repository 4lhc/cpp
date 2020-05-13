
#include <iostream>

class Complex
{
    private:
        double real{};
        double imag{};

    public:
        Complex(double r, double i)
            : real(r), imag(i)
        {}

        void const PrintConj()
        {
            std::cout << this;
        }


    friend std::ostream &operator<<(std::ostream &os, const Complex &z);



};

std::ostream &operator<<(std::ostream &os, const Complex &z)
{

    return os << z.real << " + " << z.imag << "i";
}

int main()
{



    Complex Z(9,2);
    std::cout << Z;

    Complex t(10, 1);
    t.PrintConj();
    return 0;
}
