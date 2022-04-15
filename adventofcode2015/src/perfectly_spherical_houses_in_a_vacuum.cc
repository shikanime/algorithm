#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <tuple>
#include <vector>

using position = std::pair<int, int>;

auto read(char c) -> position {
  switch (c) {
    case '^':
      return {0, +1};
    case 'v':
      return {0, -1};
    case '<':
      return {-1, 0};
    case '>':
      return {+1, 0};
  }
  throw std::runtime_error("invalid character");
}

auto visit(std::vector<char>::iterator first, std::vector<char>::iterator last,
           std::list<position>& houses) {
  houses.push_front({0, 0});
  std::transform(first, last, std::front_inserter(houses),
                 [&houses](char c) -> position {
                   auto curr = houses.front();
                   auto next = read(c);
                   return {std::get<0>(curr) + std::get<0>(next),
                           std::get<1>(curr) + std::get<1>(next)};
                 });
}

int main(int argc, char const* argv[]) {
  auto chars = std::vector<char>{std::istream_iterator<char>{std::cin}, {}};
  auto houses = std::list<position>{chars.size() + 1};
  visit(std::begin(chars), std::end(chars), houses);
  auto res = std::set<position>{std::begin(houses), std::end(houses)};
  std::cout << res.size() << std::endl;
  return 0;
}
