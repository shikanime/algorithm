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

auto has_repeated_pair(std::string_view s) {
  return std::ranges::any_of(
      std::views::iota(0ul, s.length() - 2), [&s](auto n) {
        return s.substr(n + 2).find(s.substr(n, 2)) != std::string::npos;
      });
}

auto has_separated_pair(std::string_view s) {
  auto trigrams =
      std::views::iota(0ul, s.length()) |
      std::views::transform([&s](auto n) { return s.substr(n, 3); });
  return std::ranges::any_of(
      trigrams, [](const auto& trigram) { return trigram[0] == trigram[2]; });
}

int main(int argc, char const* argv[]) {
  unsigned i = 0;
  std::string line;
  while (std::getline(std::cin, line)) {
    if (has_repeated_pair(line) && has_separated_pair(line)) i++;
  }
  std::cout << i << std::endl;
  return 0;
}
