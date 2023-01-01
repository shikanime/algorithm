#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <ranges>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

using position = std::pair<int, int>;

position read(char c) {
  switch (c) {
    case '^':
      return {0, +1};
    case 'v':
      return {0, -1};
    case '<':
      return {-1, 0};
    case '>':
      return {+1, 0};
    default:
      throw std::invalid_argument("Unexpected character");
  }
}

void visit(std::ranges::input_range auto r, std::list<position>& houses) {
  houses.push_front({0, 0});
  std::ranges::transform(r, std::front_inserter(houses),
                         [&houses](char c) -> position {
                           auto [cx, cy] = houses.front();
                           auto [nx, ny] = read(c);
                           return {cx + nx, cy + ny};
                         });
}

int main(int argc, char const* argv[]) {
  auto first = std::istream_iterator<char>{std::cin};
  std::vector<char> real;
  std::vector<char> robot;
  for (auto c = first; c != std::istream_iterator<char>{}; ++c)
    if (std::distance(first, c) % 2 == 0)
      real.push_back(*c);
    else
      robot.push_back(*c);
  auto houses = std::list<position>{real.size() + robot.size() + 2};
  visit(real, houses);
  visit(robot, houses);
  auto res = std::set<position>(std::begin(houses), std::end(houses));
  std::cout << res.size() << std::endl;
  return 0;
}
