#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>

int solve(std::istream& is, int k) {
  std::vector<int> calories{0};
  for (const auto& line : std::ranges::istream_view<std::string>(is)) {
    if (line == "") {
      calories.push_back(0);
    } else {
      calories.back() += std::stoi(line);
    }
  }
  std::vector<int> top;
  for (auto i = 0; k > i; i++) {
    auto elem = std::ranges::max_element(calories.begin(), calories.end());
    top.emplace_back(*elem);
    calories.erase(elem);
  }
  return std::accumulate(top.begin(), top.end(), 0);
}

int main(int argc, char const* argv[]) {
  std::cout << solve(std::cin, 3) << std::endl;
  return 0;
}
