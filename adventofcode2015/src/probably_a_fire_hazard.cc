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
      if (smatch[1] == "turn on")
        for (auto y = std::stoi(smatch[2]); y <= std::stoi(smatch[4]); ++y)
          for (auto x = std::stoi(smatch[3]); x <= std::stoi(smatch[5]); ++x)
            grid[y][x] = true;
      else if (smatch[1] == "turn off")
        for (auto y = std::stoi(smatch[2]); y <= std::stoi(smatch[4]); ++y)
          for (auto x = std::stoi(smatch[3]); x <= std::stoi(smatch[5]); ++x)
            grid[y][x] = false;
      else if (smatch[1] == "toggle")
        for (auto y = std::stoi(smatch[2]); y <= std::stoi(smatch[4]); ++y)
          for (auto x = std::stoi(smatch[3]); x <= std::stoi(smatch[5]); ++x)
            grid[y][x] = !grid[y][x];
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
