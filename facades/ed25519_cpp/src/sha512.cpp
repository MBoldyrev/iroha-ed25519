#include "ed25519_cpp/sha512.hpp"

#include <stddef.h>

#include "ed25519/ed25519/sha512.h"

ED25519_CPP_EXPORT bool iroha_ed25519::v2::sha512(Sha512 const& hash,
                                                  MessageView message) {
  return ::sha512(hash.data(), message.data(), message.size()) != 0;
}
