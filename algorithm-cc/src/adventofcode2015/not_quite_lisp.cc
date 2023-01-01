#include <iostream>
#include <iterator>
#include <numeric>

auto read(char c) {
  switch (c) {
    case '(':
      return 1;
    case ')':
      return -1;
    default:
      throw std::invalid_argument("Unexpected input");
  }
}

int main(int argc, char const* argv[]) {
  auto res = std::reduce(std::istream_iterator<char>{std::cin}, {}, 0,
                         [](int acc, char c) { return acc + read(c); });
  std::cout << res << std::endl;
  return 0;
}
