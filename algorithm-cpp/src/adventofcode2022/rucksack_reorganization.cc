#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
#include <vector>
#include <ranges>

unsigned int read(char c) {
  if (c >= 'a') {
    return c - 'a' + 1;
  } else if (c >= 'A') {
    return c - 'A' + 1 + 26;
  }
  throw std::invalid_argument("Invalid input");
}

unsigned int solve(std::istream& is) {
  unsigned int total_score = 0;
  for (const auto& line : std::ranges::istream_view<std::string>(is)) {
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
  std::cout << solve(std::cin) << std::endl;
  return 0;
}
