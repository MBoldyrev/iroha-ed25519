#ifndef PROJECT_ED25519_SHA256_HPP_
#define PROJECT_ED25519_SHA256_HPP_

#include "ed25519_cpp/common.hpp"
#include "ed25519_cpp_export.h"

namespace iroha_ed25519 {
namespace v2 {

/* type safe interface methods for ed25519 */

struct Sha256 : public FixedSizeMessage<32> {
  using FixedSizeMessage<32>::FixedSizeMessage;
};

/**
 * Inline hash calculation of sha256.
 * @param[out] hash calculation result
 * @param[in] message buffer to be hashed
 * @return true on success, false otherwise
 * @note some implementations may return bad code sometimes, some may not
 */
ED25519_CPP_EXPORT bool sha256(Sha256 const& hash, MessageView message);

}  // namespace v2
}  // namespace iroha_ed25519

#endif  //  PROJECT_ED25519_SHA256_HPP_
