#include <algorithm>
#include <charconv>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int solve(std::istream& is) {
  std::vector<int> numbers;
  for (const auto& line : std::ranges::istream_view<std::string>(is)) {
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
