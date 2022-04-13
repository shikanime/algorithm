#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

int main(int argc, char const *argv[]) {
  std::string str;
  std::vector<int> ribbon;
  while (std::getline(std::cin, str)) {
    int l, w, h;
    sscanf(str.c_str(), "%dx%dx%d", &l, &w, &h);
    auto sides = std::array<int, 3>{l, w, h};
    std::sort(sides.begin(), sides.end());
    auto box = 2 * sides[0] + 2 * sides[1];
    auto bow =
        std::accumulate(sides.begin(), sides.end(), 1, std::multiplies<int>());
    ribbon.push_back(box + bow);
  }
  auto res = std::accumulate(ribbon.begin(), ribbon.end(), 0);
  std::cout << res << std::endl;
  return 0;
}
