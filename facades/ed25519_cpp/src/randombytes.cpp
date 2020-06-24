#include "ed25519_cpp/randombytes.hpp"

#include <stddef.h>

#include "ed25519/ed25519/randombytes.h"

using namespace iroha_ed25519::v2;

ED25519_CPP_EXPORT bool iroha_ed25519::v2::randombytes(unsigned char *p,
                                                       int len) {
  return randombytes(p, len) != 0;
}
