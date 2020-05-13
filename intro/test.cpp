#include <iostream>

int main() {
  int lol{0};
  float fl{0.0};
  int *ptr = &lol;
  lol++;
  std::cout << "ptr" << ptr << '\n';
  std::cout << "*ptr" << *ptr << '\n';
  std::cout << "fl" << fl << '\n';
  std::cout << "lol" << lol << '\n';
  std::cout << "Hello World" << lol;
  return 0;
}
