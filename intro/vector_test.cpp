#include <iostream>
#include <vector>

struct Vertex {
  int x{0};
  int y{0};
  int z{0};
};

std::ostream &operator<<(std::ostream &stream, const Vertex &v) {
  stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
  return stream;
}

int main() { return 0; }
