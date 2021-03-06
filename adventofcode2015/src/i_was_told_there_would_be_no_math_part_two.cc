#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <ranges>
#include <regex>
#include <string>
#include <tuple>
#include <vector>

int main(int argc, char const* argv[]) {
  std::string line;
  std::vector<int> ribbon;
  while (std::getline(std::cin, line)) {
    std::smatch exp_match;
    static const auto exp_regex = std::regex("^(\\d+)x(\\d+)x(\\d+)$");
    if (std::regex_search(line, exp_match, exp_regex)) {
      auto l = std::stoi(exp_match[1]);
      auto w = std::stoi(exp_match[2]);
      auto h = std::stoi(exp_match[3]);
      auto sides = std::array<int, 3>{l, w, h};
      std::ranges::sort(sides);
      auto box = 2 * sides[0] + 2 * sides[1];
      auto bow = std::accumulate(std::begin(sides), std::end(sides), 1,
                                 std::multiplies<int>());
      ribbon.push_back(box + bow);
    }
  }
  auto res = std::accumulate(std::begin(ribbon), std::end(ribbon), 0);
  std::cout << res << std::endl;
  return 0;
}
