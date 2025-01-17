#include <algorithm>
#include <charconv>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int solve(std::istream& is) {
  std::vector<std::tuple<int, int, int, int, int, int, int>> numbers;
  for (const auto& line : std::ranges::istream_view<std::string>(is)) {
    // Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
    // Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
    // Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
    // Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
    // Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
    // Game 6: 1 red, 1 green, 1 blue
    std::array<int, 6> game;
    for (const auto x : std::views::split(line, ":") {
      std::array<int, 3> colors;
      for (const auto y : std::views::split(x, ",") {
        std::array<int, 2> color;
        std::from_chars(y.begin(), y.end(), color[0]);
        std::from_chars(y.begin(), y.end(), color[1]);
        colors[color[1]] = color[0];
      }
      game[colors[0]] = colors[1];
    }
  }
  return std::accumulate(numbers.begin(), numbers.end(), 0);
}

int main(int argc, char const* argv[]) {
  std::cout << solve(std::cin) << std::endl;
  return 0;
}
