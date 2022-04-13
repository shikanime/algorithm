#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <tuple>
#include <vector>

auto position_update(char c) -> std::pair<int, int> {
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

int main(int argc, char const* argv[]) {
  auto chars = std::vector<char>{std::istream_iterator<char>(std::cin),
                                 std::istream_iterator<char>()};
  auto houses = std::list<std::pair<int, int>>{chars.size(), {0, 0}};
  std::transform(chars.begin(), chars.end(), std::front_inserter(houses),
                 [&houses](char c) {
                   auto curr = houses.front();
                   auto next = position_update(c);
                   return std::pair<int, int>{
                       std::get<0>(curr) + std::get<0>(next),
                       std::get<1>(curr) + std::get<1>(next)};
                 });
  auto res = std::set<std::pair<int, int>>(houses.begin(), houses.end());
  std::cout << res.size() << std::endl;
  return 0;
}
