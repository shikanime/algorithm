#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

template <class InputIterator>
auto has_enough_vowels(InputIterator first, InputIterator last) {
  auto vowels = std::count_if(first, last, [](char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  });
  return vowels >= 3;
}

template <class InputIterator>
auto has_pair(InputIterator first, InputIterator last) {
  return std::any_of(first, last, [](std::pair<char, char> pair) {
    return pair.first == pair.second;
  });
}

template <class InputIterator>
auto has_only_valid_chars(InputIterator first, InputIterator last) {
  static const auto excluded_pairs = std::vector<std::pair<char, char>>{
      {'a', 'b'}, {'c', 'd'}, {'p', 'q'}, {'x', 'y'}};
  return std::none_of(first, last, [](auto& s) {
    return std::find(std::begin(excluded_pairs), std::end(excluded_pairs), s) !=
           std::end(excluded_pairs);
  });
}

template <class InputIterator, class OutputIterator>
auto window(InputIterator first, InputIterator last, OutputIterator out) {
  std::transform(first, last - 1, first + 1, out,
                 [](char a, char b) -> std::pair<char, char> {
                   return {a, b};
                 });
}

int main(int argc, char const* argv[]) {
  int i = 0;
  std::string line;
  while (std::getline(std::cin, line)) {
    if (!has_enough_vowels(std::begin(line), std::end(line))) continue;
    std::vector<std::pair<char, char>> pairs;
    window(std::begin(line), std::end(line), std::back_inserter(pairs));
    if (!has_pair(std::begin(pairs), std::end(pairs)) ||
        !has_only_valid_chars(std::begin(pairs), std::end(pairs)))
      continue;
    i++;
  }
  std::cout << i << std::endl;
  return 0;
}
