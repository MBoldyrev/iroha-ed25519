#include "ed25519_cpp/sha256.hpp"

#include <stddef.h>

#include "ed25519/ed25519/sha256.h"

ED25519_CPP_EXPORT bool iroha_ed25519::v2::sha256(Sha256 const& hash,
                                                  MessageView message) {
  return ::sha256(hash.data(), message.data(), message.size()) != 0;
}
