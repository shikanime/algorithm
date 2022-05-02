#include <concepts>
#include <iostream>
#include <map>
#include <optional>
#include <regex>
#include <string>
#include <tuple>
#include <variant>

namespace aoc {
template <std::equality_comparable K, std::integral V>
using node = std::variant<K, V>;
template <std::equality_comparable K, std::integral V>
using and_gate = std::tuple<node<K, V>, node<K, V>>;
template <std::equality_comparable K, std::integral V>
using or_gate = std::tuple<node<K, V>, node<K, V>>;
template <std::equality_comparable K, std::integral V>
using not_gate = std::tuple<node<K, V>>;
template <std::equality_comparable K, std::integral V>
using lshift_gate = std::tuple<node<K, V>, node<K, V>>;
template <std::equality_comparable K, std::integral V>
using rshift_gate = std::tuple<node<K, V>, node<K, V>>;
template <std::equality_comparable K, std::integral V>
using edge = std::variant<and_gate<K, V>, or_gate<K, V>, not_gate<K, V>,
                          lshift_gate<K, V>, rshift_gate<K, V>>;
template <std::equality_comparable K, std::integral V>
using graph = std::map<K, edge<K, V>>;
}  // namespace aoc

int main(int argc, char const* argv[]) {
  aoc::graph<std::string, int> graph;
  std::string line;
  while (std::getline(std::cin, line)) {
    static const std::regex command_regex(
        " (?:\\d+) (?:NOT|AND|OR|RSHIFT|LSHIFT) (\\d+) -> (\\d+)");
    std::smatch smatch;
    if (std::regex_search(line, smatch, command_regex)) {
    }
  }
  return 0;
}
