#include <iostream>
#include <map>
#include <ranges>
#include <regex>
#include <variant>

struct rock;
struct paper;
struct scisor;

unsigned int get_shape_score(std::string_view s) {
  if (s == "X") {
    return 1;
  } else if (s == "Y") {
    return 2;
  } else if (s == "Z") {
    return 3;
  }
  throw std::invalid_argument("Invalid input");
}

std::strong_ordering compare_command(std::string_view player,
                                     std::string_view opponent) {
  if ((player == "X" && opponent == "C") ||
      (player == "Y" && opponent == "A") ||
      (player == "Z" && opponent == "B")) {
    return std::strong_ordering::greater;
  } else if ((player == "X" && opponent == "A") ||
             (player == "Y" && opponent == "B") ||
             (player == "Z" && opponent == "C")) {
    return std::strong_ordering::equivalent;
  } else if ((player == "X" && opponent == "B") ||
             (player == "Y" && opponent == "C") ||
             (player == "Z" && opponent == "A")) {
    return std::strong_ordering::less;
  }
  throw std::invalid_argument("Invalid input");
}

unsigned int solve(std::istream& is) {
  unsigned int total_score = 0;
  for (const auto& line : std::ranges::istream_view<std::string>(is)) {
    std::smatch exp_match;
    if (static const auto exp_regex = std::regex("^(\\w) (\\w)$");
        !std::regex_search(line, exp_match, exp_regex)) {
      throw std::invalid_argument("Invalid input");
    }
    auto const& opponent = exp_match[1];
    auto const& player = exp_match[2];
    auto shape_score = get_shape_score(player.str());
    auto cmd = compare_command(player.str(), opponent.str());
    if (cmd == std::strong_ordering::greater) {
      total_score += 6 + shape_score;
    } else if (cmd == std::strong_ordering::equivalent) {
      total_score += 3 + shape_score;
    } else if (cmd == std::strong_ordering::less) {
      total_score += 0 + shape_score;
    } else {
      throw std::invalid_argument("Invalid input");
    }
  }
  return total_score;
}

int main(int argc, char const* argv[]) {
  std::cout << solve(std::cin) << std::endl;
  return 0;
}
