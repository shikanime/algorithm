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
    return 0;
  } else if (s == "Y") {
    return 3;
  } else if (s == "Z") {
    return 6;
  }
  throw std::invalid_argument("Invalid input");
}

unsigned int get_game_score(std::string_view expectation,
                            std::string_view opponent) {
  if (expectation == "X") {
    if (opponent == "A") {
      return 3;
    } else if (opponent == "B") {
      return 1;
    } else if (opponent == "C") {
      return 2;
    }
  } else if (expectation == "Y") {
    if (opponent == "A") {
      return 1;
    } else if (opponent == "B") {
      return 2;
    } else if (opponent == "C") {
      return 3;
    }
  } else if (expectation == "Z") {
    if (opponent == "A") {
      return 2;
    } else if (opponent == "B") {
      return 3;
    } else if (opponent == "C") {
      return 1;
    }
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
    auto const& expectation = exp_match[2];
    auto shape_score = get_shape_score(expectation.str());
    auto game_score = get_game_score(expectation.str(), opponent.str());
    total_score += game_score + shape_score;
  }
  return total_score;
}

int main(int argc, char const* argv[]) {
  std::cout << solve(std::cin) << std::endl;
  return 0;
}
