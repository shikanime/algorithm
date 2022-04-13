#include <iostream>
#include <iterator>
#include <numeric>

int main(int argc, char const* argv[]) {
  auto res =
      std::reduce(std::istream_iterator<char>{std::cin}, {}, 0,
                  [](int acc, char c) { return acc + (c == '(' ? 1 : -1); });
  std::cout << res << std::endl;
  return 0;
}
