#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <ranges>
#include <regex>
#include <string>

enum class action { turn_on, turn_off, toggle };

action read_action(std::string_view s) {
  if (s == "turn on")
    return action::turn_on;
  else if (s == "turn off")
    return action::turn_off;
  else if (s == "toggle")
    return action::toggle;
  else
    throw std::invalid_argument("Unexpected action");
}

auto cartesian_product_view(std::ranges::input_range auto a,
                            std::ranges::input_range auto b) {
  return a | std::views::transform([b](const auto x) {
           return b | std::views::transform([x](const auto y) {
                    return std::pair{x, y};
                  });
         }) |
         std::views::join;
}

int main(int argc, char const* argv[]) {
  std::array<std::array<bool, 1000>, 1000> grid{{false}};
  std::string line;
  while (std::getline(std::cin, line)) {
    static const std::regex command_regex(
        "(turn on|turn off|toggle) (\\d+),(\\d+) through (\\d+),(\\d+)");
    std::smatch smatch;
    if (std::regex_search(line, smatch, command_regex)) {
      auto ax = std::stoi(smatch[2]);
      auto ay = std::stoi(smatch[4]);
      auto bx = std::stoi(smatch[3]);
      auto by = std::stoi(smatch[5]);
      auto action = read_action(smatch[1].str());
      auto matrix = cartesian_product_view(std::views::iota(ax, ay + 1),
                                           std::views::iota(bx, by + 1));
      std::ranges::for_each(matrix, [&grid, &action](const auto xy) {
        switch (action) {
          case action::turn_on:
            grid[xy.first][xy.second] = true;
            break;
          case action::turn_off:
            grid[xy.first][xy.second] = false;
            break;
          case action::toggle:
            grid[xy.first][xy.second] = !grid[xy.first][xy.second];
            break;
          default:
            break;
        }
      });
    }
  }
  auto res = std::accumulate(
      std::begin(grid), std::end(grid), 0, [](const auto acc, const auto& row) {
        return acc + std::ranges::count(std::begin(row), std::end(row), true);
      });
  std::cout << res << std::endl;
  return 0;
}
