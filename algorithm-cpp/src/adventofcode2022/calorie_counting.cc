#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <ranges>

int solve(std::istream& is) {
  std::vector<int> calories{0};
  for (const auto& line : std::ranges::istream_view<std::string>(is)) {
    if (line == "") {
      calories.push_back(0);
    } else {
      calories.back() += std::stoi(line);
    }
  }
  return *std::ranges::max_element(calories.begin(), calories.end());
}

int main(int argc, char const* argv[]) {
  std::cout << solve(std::cin) << std::endl;
  return 0;
}
