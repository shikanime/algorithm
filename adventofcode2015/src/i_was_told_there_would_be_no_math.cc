#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>
#include <string>

int main(int argc, char const* argv[]) {
  std::string str;
  std::vector<int> papers;
  while (std::getline(std::cin, str)) {
    int l, w, h;
    sscanf(str.c_str(), "%dx%dx%d", &l, &w, &h);
    auto lw = l * w;
    auto wh = w * h;
    auto hl = h * l;
    auto box = 2 * (lw + wh + hl);
    auto slack = std::min(lw, std::min(wh, hl));
    papers.push_back(box + slack);
  }
  auto res = std::accumulate(papers.begin(), papers.end(), 0);
  std::cout << res << std::endl;
  return 0;
}
