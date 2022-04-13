#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <ranges>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

auto visit(std::vector<char>::iterator first, std::vector<char>::iterator last,
           std::list<std::pair<int, int>> &houses) {
  houses.push_front({0, 0});
  std::transform(
      first, last, std::front_inserter(houses),
      [&houses](char c) -> std::pair<int, int> {
        switch (c) {
        case '^':
          return {std::get<0>(houses.front()), std::get<1>(houses.front()) + 1};
        case 'v':
          return {std::get<0>(houses.front()), std::get<1>(houses.front()) - 1};
        case '<':
          return {std::get<0>(houses.front()) - 1, std::get<1>(houses.front())};
        case '>':
          return {std::get<0>(houses.front()) + 1, std::get<1>(houses.front())};
        }
        throw std::runtime_error("invalid character");
      });
}

int main(int argc, char const *argv[]) {
  auto chars = std::vector<char>{std::istream_iterator<char>(std::cin),
                                 std::istream_iterator<char>()};
  std::vector<char> real;
  std::vector<char> robot;
  for (auto c = std::begin(chars); c != std::end(chars); ++c)
    if (std::distance(std::begin(chars), c) % 2 == 0)
      real.push_back(*c);
    else
      robot.push_back(*c);
  auto houses = std::list<std::pair<int, int>>{chars.size() + 2};
  visit(std::begin(real), std::end(real), houses);
  visit(std::begin(robot), std::end(robot), houses);
  auto res = std::set<std::pair<int, int>>(houses.begin(), houses.end());
  std::cout << res.size() << std::endl;
  return 0;
}
