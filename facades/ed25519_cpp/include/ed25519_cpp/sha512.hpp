#ifndef PROJECT_ED25519_SHA512_HPP_
#define PROJECT_ED25519_SHA512_HPP_

#include "ed25519_cpp/common.hpp"
#include "ed25519_cpp_export.h"

namespace iroha_ed25519 {
namespace v2 {

/* type safe interface methods for ed25519 */

struct Sha512 : public FixedSizeMessage<64> {
  using FixedSizeMessage<64>::FixedSizeMessage;
};

/**
 * Inline hash calculation of sha512.
 * @param[out] hash calculation result
 * @param[in] message buffer to be hashed
 * @return true on success, false otherwise
 * @note some implementations may return bad code sometimes, some may not
 */
ED25519_CPP_EXPORT bool sha512(Sha512 const& hash, MessageView message);

}  // namespace v2
}  // namespace iroha_ed25519

#endif  //  PROJECT_ED25519_SHA512_HPP_
