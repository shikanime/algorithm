#include <iterator>
#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char const *argv[])
{
  auto v = std::vector<char>(
      std::istream_iterator<char>(std::cin),
      std::istream_iterator<char>());
  auto s = std::accumulate(
      std::next(v.begin()), v.end(),
      std::vector<int>(v.size()),
      [](std::vector<int> a, b)
      { return a + (b == '(' ? 1 : -1); });
  auto l = std::lower_bound(s.begin(), s.end(), 0);
  std::cout << std::distance(s.begin(), l) << std::endl;
  return 0;
}
