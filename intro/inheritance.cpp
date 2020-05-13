#include <iostream>

struct Base
{
  virtual void test_func() = 0;
  int data{0};

};

struct Derived : Base{
  virtual void test_func(int )

};
