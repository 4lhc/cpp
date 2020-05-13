#include <iostream>
#include <cmath>


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double mealcost{};
    int tip_perc{}, tax_perc{};
    std::cin >> mealcost >> tip_perc >> tax_perc;
    //std::cout << "The total meal cost is " << mealcost*( 1 + tip_perc/100 + tax_perc/100 ) << " dollars.";
    std::cout << "The total meal cost is " << std::round(mealcost*(1 + static_cast<double>(tax_perc)/100 + static_cast<double>(tip_perc)/100)) << " dollars.";
    return 0;
}
