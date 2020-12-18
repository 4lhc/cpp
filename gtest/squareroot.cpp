#include "squareroot.h"

//g++ -o runtest squareroot.cpp tests.cpp -lgtest -lpthread

double squareRt(const double a) {
    double b = sqrt(a);
    if(b != b) { // nan check
        return -1.0;
    }else{
        return sqrt(a);
    }
}
