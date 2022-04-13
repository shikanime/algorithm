#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <vector>

int main(int argc, char const* argv[]) {
  int i = 0;
  std::string str;
  while (std::getline(std::cin, str)) {
    auto vowels = std::count_if(str.begin(), str.end(), [](char c) {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    });
    if (vowels < 3) continue;
    std::vector<std::pair<char, char>> pairs;
    std::transform(str.begin(), str.end() - 1, str.begin() + 1,
                   std::back_inserter(pairs), [](char a, char b) {
                     return std::pair<char, char>{a, b};
                   });
    auto has_pair = std::any_of(
        pairs.begin(), pairs.end(),
        [](std::pair<char, char> pair) { return pair.first == pair.second; });
    if (!has_pair) continue;
    std::set<std::pair<char, char>> in{pairs.begin(), pairs.end()};
    std::set<std::pair<char, char>> exclude{
        {'a', 'b'}, {'c', 'd'}, {'p', 'q'}, {'x', 'y'}};
    auto has_exclude = std::any_of(in.begin(), in.end(), [exclude](auto& s) {
      return exclude.find(s) != exclude.end();
    });
    if (has_exclude) continue;
    i++;
  }
  std::cout << i << std::endl;
  return 0;
}
