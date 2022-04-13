#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

int main(int argc, char const *argv[]) {
  auto chars = std::vector<char>{std::istream_iterator<char>(std::cin),
                                 std::istream_iterator<char>()};
  auto houses = std::list<std::pair<int, int>>{chars.size(), {0, 0}};
  std::transform(
      chars.begin(), chars.end(), std::front_inserter(houses),
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
  auto res = std::set<std::pair<int, int>>(houses.begin(), houses.end());
  std::cout << res.size() << std::endl;
  return 0;
}
