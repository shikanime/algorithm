#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

auto read(char c) {
  switch (c) {
    case '(':
      return 1;
    case ')':
      return -1;
  }
  throw std::runtime_error("invalid input");
}

int main(int argc, char const* argv[]) {
  std::vector<int> acc;
  std::transform(std::istream_iterator<char>{std::cin}, {}, std::begin(acc),
                 &read);
  std::partial_sum(std::begin(acc), std::end(acc), std::begin(acc));
  auto res =
      std::find_if(std::begin(acc), std::end(acc), [](int a) { return a < 0; });
  std::cout << std::distance(std::begin(acc), res) + 1 << std::endl;
  return 0;
}
