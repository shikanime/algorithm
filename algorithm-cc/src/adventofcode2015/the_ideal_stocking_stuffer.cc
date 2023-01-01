#include <openssl/evp.h>

#include <iostream>
#include <limits>
#include <optional>
#include <string>

template <std::integral T>
std::optional<T> search(std::string& chars) {
  auto ctx = EVP_MD_CTX_create();
  auto md_func = EVP_md5();
  EVP_MD_CTX_init(ctx);
  for (T nonce = 0; nonce < std::numeric_limits<T>::max(); ++nonce) {
    if (!EVP_DigestInit_ex(ctx, md_func, nullptr)) {
      throw std::invalid_argument("EVP_DigestInit_ex failed");
    }
    auto challenge = chars + std::to_string(nonce);
    if (!EVP_DigestUpdate(ctx, challenge.c_str(), challenge.length())) {
      throw std::invalid_argument("EVP_DigestUpdate failed");
    }
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned digest_len = 0;
    if (!EVP_DigestFinal_ex(ctx, digest, &digest_len)) {
      throw std::invalid_argument("EVP_DigestFinal_ex failed");
    }
    if (digest_len != EVP_MD_size(md_func)) {
      throw std::invalid_argument(
          "EVP_DigestFinal_ex returned unexpected length");
    }
    if (digest[0] == 0 && digest[1] == 0 && (digest[2] & 0xf0) == 0)
      return {nonce};
  }
  EVP_MD_CTX_free(ctx);
  return std::nullopt;
}

int main(int argc, char const* argv[]) {
  auto chars = std::string{std::istreambuf_iterator<char>{std::cin}, {}};
  if (auto nonce = search<unsigned int>(chars))
    std::cout << *nonce << std::endl;
}
