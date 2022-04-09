#include <iterator>
#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char const *argv[])
{
    auto chars = std::vector<char>(
        std::istream_iterator<char>(std::cin),
        std::istream_iterator<char>());
    auto acc = std::vector<int>(chars.size());
    std::transform(
        std::begin(chars), std::end(chars),
        std::begin(acc),
        [](char a) -> int
        { return a == '(' ? 1 : -1; });
    std::partial_sum(
        std::begin(acc), std::end(acc),
        std::begin(acc));
    auto res = std::find_if(
        std::begin(acc), std::end(acc),
        [](int a) -> int
        { return a < 0; });
    std::cout << std::distance(std::begin(acc), res) + 1 << std::endl;
    return 0;
}
