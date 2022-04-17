#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <ranges>
#include <set>
#include <string>
#include <string_view>
#include <vector>

int main(int argc, char const* argv[]) {
  unsigned i = 0;
  std::string line;
  while (std::getline(std::cin, line)) {
    auto has_repeated_pair = std::ranges::any_of(
        std::views::iota(0ul, line.length() - 2), [&line](auto n) {
          return line.substr(n + 2).find(line.substr(n, 2)) !=
                 std::string::npos;
        });
    auto trigrams = std::views::iota(0ul, line.length()) |
                    std::views::transform([&line](auto n) {
                      return std::string_view{line}.substr(n, 3);
                    });
    auto has_separated_pair = std::ranges::any_of(
        trigrams, [&line](const auto& s) { return s[0] == s[2]; });
    if (has_repeated_pair && has_separated_pair) i++;
  }
  std::cout << i << std::endl;
  return 0;
}
