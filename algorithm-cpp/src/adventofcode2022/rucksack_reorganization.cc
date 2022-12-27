#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

unsigned int read(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a' + 1;
  }
  if (c >= 'A' && c <= 'Z') {
    return c - 'A' + 1 + 26;
  }
  throw std::invalid_argument("Invalid input");
}

unsigned int solve(std::ranges::input_range auto ir) {
  unsigned int total_score = 0;
  for (const auto& line : ir) {
    std::set<unsigned int> left;
    std::set<unsigned int> right;
    for (auto i = 0; line.length() / 2 > i; i++) {
      left.insert(read(line[i]));
      right.insert(read(line[line.length() - i - 1]));
    }
    std::vector<unsigned int> intersection;
    std::ranges::set_intersection(left, right,
                                  std::back_inserter(intersection));
    total_score += std::accumulate(intersection.begin(), intersection.end(), 0);
  }
  return total_score;
}

int main(int argc, char const* argv[]) {
  std::cout << solve(std::ranges::istream_view<std::string>(std::cin))
            << std::endl;
  return 0;
}
