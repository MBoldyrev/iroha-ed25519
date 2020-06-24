#ifndef PROJECT_ED25519_RANDOMBYTES_HPP_
#define PROJECT_ED25519_RANDOMBYTES_HPP_

#include "ed25519_cpp_export.h"

namespace iroha_ed25519 {
namespace v2 {

/**
 * Fills preallocated buffer p of length len with random data.
 * @param[out] p buffer of length len
 * @param[in] len length
 * @return true on success, false otherwise
 * @note You should always check return code of randombytes
 */
ED25519_CPP_EXPORT bool randombytes(unsigned char *p, int len);

}  // namespace v2
}  // namespace iroha_ed25519

#endif  //  PROJECT_ED25519_RANDOMBYTES_HPP_
