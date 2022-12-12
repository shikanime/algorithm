#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

int solve(std::istream& is) {
  std::vector<int> calories;
  std::for_each(std::istream_iterator<std::string>{std::cin},
                std::istream_iterator<std::string>{},
                [&calories](std::string c) {
                  if (c == "") {
                    calories.push_back(0);
                  } else {
                    calories.back() += std::atoi(c.c_str());
                  }
                });
  return *std::max_element(calories.begin(), calories.end());
}

int main(int argc, char const* argv[]) {
  std::cout << solve(std::cin) << std::endl;
  return 0;
}
