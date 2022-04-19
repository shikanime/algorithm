#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <ranges>
#include <regex>
#include <string>

int main(int argc, char const* argv[]) {
  std::array<std::array<bool, 1000>, 1000> grid{{false}};
  std::string line;
  while (std::getline(std::cin, line)) {
    static const std::regex command_regex(
        "(turn on|turn off|toggle) (\\d+),(\\d+) through (\\d+),(\\d+)");
    std::smatch smatch;
    if (std::regex_search(line, smatch, command_regex))
      std::ranges::for_each(
          std::views::iota(std::stoi(smatch[2]), std::stoi(smatch[4]) + 1) |
              std::views::transform([&smatch](auto x) {
                return std::views::iota(std::stoi(smatch[3]),
                                        std::stoi(smatch[5]) + 1) |
                       std::views::transform([x](auto y) {
                         return std::pair{x, y};
                       });
              }) |
              std::views::join,
          [&grid, &smatch](auto xy) {
            if (smatch[1] == "turn on")
              grid[xy.first][xy.second] = true;
            else if (smatch[1] == "turn off")
              grid[xy.first][xy.second] = false;
            else
              grid[xy.first][xy.second] = !grid[xy.first][xy.second];
          });
  }
  auto res = std::accumulate(
      std::begin(grid), std::end(grid), 0, [](int acc, const auto& row) {
        return acc + std::accumulate(
                         std::begin(row), std::end(row), 0,
                         [](int acc, bool b) { return acc + (b ? 1 : 0); });
      });
  std::cout << res << std::endl;
  return 0;
}
