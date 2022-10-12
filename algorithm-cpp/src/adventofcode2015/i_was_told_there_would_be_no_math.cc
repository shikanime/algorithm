#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <tuple>
#include <vector>

int main(int argc, char const* argv[]) {
  std::string line;
  std::vector<int> papers;
  while (std::getline(std::cin, line)) {
    std::smatch exp_match;
    static const auto exp_regex = std::regex("^(\\d+)x(\\d+)x(\\d+)$");
    if (std::regex_search(line, exp_match, exp_regex)) {
      auto l = std::stoi(exp_match[1]);
      auto w = std::stoi(exp_match[2]);
      auto h = std::stoi(exp_match[3]);
      auto lw = l * w;
      auto wh = w * h;
      auto hl = h * l;
      auto box = 2 * (lw + wh + hl);
      auto slack = std::min(lw, std::min(wh, hl));
      papers.push_back(box + slack);
    } else {
    }
  }
  auto res = std::accumulate(std::begin(papers), std::end(papers), 0);
  std::cout << res << std::endl;
  return 0;
}
