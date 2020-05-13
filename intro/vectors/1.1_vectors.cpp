#include <iostream>
#include <vector>
#include <algorithm>

struct Fraction
{
        int numerator = 0;
        int denominator = 0;

        Fraction(const int& n, const int& d)
        {
            numerator = n;
            denominator = d;
        }

        void printFraction()
        {
            std::cout << numerator << "/" << denominator << std::endl;
        }
        friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

};

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
    os << f.numerator << "/" << f.denominator;
    return os;

}

template <typename T>
void printVec(const T& v)
{
    //for (auto it = v.begin(); it != v.end(); it++)
    //{
        //std::cout << *it << std::endl;
    //}
    for( const auto& i : v )
        std::cout << i << std::endl;

}


int main()
{
    std::vector<int> list1 = {9, 4, 7, 1, 2};

    auto count = list1.begin();
    std::cout << *(count + 1)  << " | " << *(++count)
                               << " | " << *(++count)
                               << " | " << *(count++)
                               << " | " << *(count)  << std::endl;


    Fraction f1(1, 1);
    std::vector<Fraction> fvec(5, f1);

    auto it = list1.begin();
    *it = 34;

    printVec(fvec);
    printVec(list1);


    //int count = 0;
    //std::vector<double> list3;
    //double x;
    //double sum (0);

    //while(std::cin >> x)
    //{

        //sum += x;
        //list3.push_back(x);
    //}

    //std::vector<double>::size_type st = list3.size();
    //std::cout << "\nSize of list3: " << st;
    //std::cout << "\nSUM: " << sum;


}
