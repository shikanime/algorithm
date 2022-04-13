#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char const* argv[]) {
  auto chars = std::vector<char>{std::istream_iterator<char>{std::cin}, {}};
  return 0;
}
