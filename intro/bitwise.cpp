#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>

using std::vector;
int main() {
    int REGA = 0xB6;
    std::cout << "REGA = " << std::hex << REGA  << std::dec << std::endl;
    REGA |= 0b00010001;
    REGA &= 0b01111011;
    std::cout << "REGA = " << std::hex << REGA  << std::dec << std::endl;
  return 0;

}
