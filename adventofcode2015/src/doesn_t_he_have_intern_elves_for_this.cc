#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

template <std::ranges::input_range R>
auto has_enough_vowels(R r) {
  auto vowels = std::ranges::count_if(r, [](char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  });
  return vowels >= 3;
}

template <std::ranges::input_range R>
auto has_pair(R r) {
  return std::ranges::any_of(
      r, [](std::pair<char, char>& pair) { return pair.first == pair.second; });
}

template <std::ranges::input_range R>
auto has_only_valid_chars(R r) {
  static const auto excluded = std::vector<std::pair<char, char>>{
      {'a', 'b'}, {'c', 'd'}, {'p', 'q'}, {'x', 'y'}};
  return std::ranges::none_of(r, [](std::pair<char, char>& pair) {
    return std::ranges::find(std::views::all(excluded), pair) !=
           std::end(excluded);
  });
}

template <class I, class O>
auto window(I first, I last, O out) {
  std::transform(first, last - 1, first + 1, out,
                 [](char a, char b) -> std::pair<char, char> {
                   return {a, b};
                 });
}

int main(int argc, char const* argv[]) {
  unsigned int i = 0;
  std::string line;
  while (std::getline(std::cin, line))
    if (has_enough_vowels(std::views::all(line))) {
      std::vector<std::pair<char, char>> pairs;
      window(std::begin(line), std::end(line), std::back_inserter(pairs));
      if (has_pair(std::views::all(pairs)) &&
          has_only_valid_chars(std::views::all(pairs)))
        i++;
    }
  std::cout << i << std::endl;
  return 0;
}
