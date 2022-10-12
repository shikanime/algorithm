#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
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
  std::ranges::copy(
      std::ranges::istream_view<char>(std::cin) | std::views::transform(&read),
      std::back_inserter(acc));
  std::partial_sum(std::begin(acc), std::end(acc), std::begin(acc));
  auto res = std::ranges::find_if(acc, [](int a) { return a < 0; });
  std::cout << std::distance(std::begin(acc), res) + 1 << std::endl;
  return 0;
}
