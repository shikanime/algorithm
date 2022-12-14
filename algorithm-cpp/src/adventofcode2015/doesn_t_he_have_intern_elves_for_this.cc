#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

auto has_enough_vowels(std::ranges::input_range auto r) {
  auto vowels = std::ranges::count_if(r, [](char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  });
  return vowels >= 3;
}

auto has_pair(std::ranges::input_range auto r) {
  return std::ranges::any_of(r, [](std::pair<char, char> const& pair) {
    return pair.first == pair.second;
  });
}

auto has_only_valid_chars(std::ranges::input_range auto r) {
  static const auto excluded = std::vector<std::pair<char, char>>{
      {'a', 'b'}, {'c', 'd'}, {'p', 'q'}, {'x', 'y'}};
  return std::ranges::none_of(r, [](std::pair<char, char>& pair) {
    return std::ranges::find(excluded, pair) != std::end(excluded);
  });
}

auto window(std::input_iterator auto first, std::input_iterator auto last,
            std::output_iterator<std::pair<char, char>> auto out) {
  std::transform(first, last - 1, first + 1, out,
                 [](char a, char b) -> std::pair<char, char> {
                   return {a, b};
                 });
}

int main(int argc, char const* argv[]) {
  unsigned int i = 0;
  std::string line;
  while (std::getline(std::cin, line))
    if (has_enough_vowels(line)) {
      std::vector<std::pair<char, char>> pairs;
      window(std::begin(line), std::end(line), std::back_inserter(pairs));
      if (has_pair(pairs) && has_only_valid_chars(pairs)) i++;
    }
  std::cout << i << std::endl;
  return 0;
}
