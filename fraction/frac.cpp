#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
class Fraction
 {
	protected:
		int num;
		int den;
	public:
        int x;
		void print(void);
		Fraction(const int &n,const int &d);
		Fraction();
		void inverse(void);
		void simplify(void);
//		void write2file(std::ofstream&,Fraction&);
		friend Fraction operator+(Fraction&, Fraction&);
	 	friend Fraction operator*(Fraction&, Fraction&);
		friend Fraction operator/(Fraction&, Fraction&);
        friend std::ostream& operator<<(std::ostream&, Fraction&);
        friend std::ofstream& operator<<(std::ofstream&, Fraction&);
    private:
        int p;

};

Fraction::Fraction(const int &n,const int &d)
{
	num = n;
	den = d;
}
Fraction::Fraction()
{
    num = 1; den = 1;
}
void Fraction::print()
{
	cout << num <<"/" << den << endl;
}
void Fraction::inverse()
{
	int tmp = num;
	    num = den;
	    den = tmp;
}
void Fraction::simplify()
{
	int gcd,i;
	for(i=1;i<=num&&i<=den;i++)
	{
		if(num%i==0 && den%i==0)
		{
			gcd=i;
		}
	}

	num=num/gcd;
	den=den/gcd;
}
 Fraction operator +(Fraction &f1,Fraction &f2)
{
	Fraction f3(0,0);
	f3.num = f1.num*f2.den+f1.den*f2.num;
	f3.den = f1.den*f2.den;
	return f3;
}
Fraction operator *(Fraction &f1,Fraction &f2)
{
        Fraction f3(0,0);
        f3.num = f1.num*f2.num;
        f3.den = f1.den*f2.den;
        return f3;
}
 Fraction operator /(Fraction &f1,Fraction &f2)
{
        Fraction f3(0,0);
        f2.inverse();
	f3 = f1*f2;

        return f3;
}

std::ofstream &operator<<(std::ofstream &os, Fraction &f)
{
    os.write(reinterpret_cast<char*>(&f.num), sizeof(f.num));
    os.write(reinterpret_cast<char*>(&f.den), sizeof(f.den));
    return os;
}


std::ostream &operator<<(std::ostream &os, Fraction &f)
{
    os << f.num << "/" << f.den ;
    return os;
}


template <typename T>
void printN(T &var)
{
    std::cout << var << std::endl;
}

int main(int argc, char** argv)
{

	Fraction f1(1, 2);
	Fraction f2(1, 3);
    cout << "printN: ";
    printN(f1);
	Fraction f;

	f = f1 + f2;
	cout << "addition of two fractions :" << f << endl;

	f = f1 * f2;
	cout << "multiplication :" << f << endl;



	f = f1/f2;
	cout << "Division :" << f << endl;

	f.simplify();
 	std::ofstream of( argv[1], std::ios::binary);

    of << f; //writing to file
	of.close();
}

