#include <algorithm>
#include <array>
#include <charconv>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

static std::array<std::string, 9> tokens{
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solve(std::istream& is) {
  std::vector<int> numbers;
  for (auto& line : std::ranges::istream_view<std::string>(is)) {
    for (std::size_t i = 0; i < line.size(); i++) {
      for (std::size_t j = 0; j < tokens.size(); j++) {
        if (tokens[j].compare(std::string_view(
                line.begin() + i, line.begin() + std::min(i + tokens[j].size(),
                                                          line.size()))) == 0) {
          auto s = std::to_string(j + 1);
          for (std::size_t k = 0; k < s.size(); k++) {
            line[i + k] = s[k];
          }
        }
      }
    }
    auto first = std::ranges::find_if(
        line, [](unsigned char c) { return std::isdigit(c); });
    auto last =
        std::ranges::find_if(line.rbegin(), line.rend(),
                             [](unsigned char c) { return std::isdigit(c); });
    std::array<char, 2> chars{*first, *last};
    std::from_chars(chars.begin(), chars.end(), numbers.emplace_back());
  }
  return std::accumulate(numbers.begin(), numbers.end(), 0);
}

int main(int argc, char const* argv[]) {
  std::cout << solve(std::cin) << std::endl;
  return 0;
}
