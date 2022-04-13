#include <openssl/md5.h>

#include <iomanip>
#include <iostream>
#include <limits>
#include <optional>
#include <sstream>
#include <string>

template <typename T>
auto search(std::string chars) -> std::optional<T> {
  for (T nonce = 0; nonce < std::numeric_limits<T>::max(); ++nonce) {
    auto challenge = chars + std::to_string(nonce);
    unsigned char digest[MD5_DIGEST_LENGTH] = {};
    MD5(reinterpret_cast<const unsigned char*>(challenge.c_str()),
        challenge.length(), digest);
    if (digest[0] == 0 && digest[1] == 0 && (digest[2] & 0xf0) == 0)
      return {nonce};
  }
  return std::nullopt;
}

int main(int argc, char const* argv[]) {
  auto chars = std::string{std::istreambuf_iterator<char>(std::cin), {}};
  if (auto nonce = search<unsigned int>(chars))
    std::cout << *nonce << std::endl;
}
