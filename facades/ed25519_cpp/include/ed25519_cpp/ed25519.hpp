#ifndef PROJECT_ED25519_HPP_
#define PROJECT_ED25519_HPP_

#include "ed25519_cpp/common.hpp"
#include "ed25519_cpp_export.h"

namespace iroha_ed25519 {
namespace v2 {

/* type safe interface methods for ed25519 */

struct PublicKeyView : public FixedSizeView<32> {
  using FixedSizeView<32>::FixedSizeView;
};

struct PrivateKeyView : public FixedSizeView<32> {
  using FixedSizeView<32>::FixedSizeView;
};

struct SignatureView : public FixedSizeView<64> {
  using FixedSizeView<64>::FixedSizeView;
};

struct PublicKey : public FixedSizeMessage<32> {
  using FixedSizeMessage<32>::FixedSizeMessage;
};

struct PrivateKey: public FixedSizeMessage<32> {
  using FixedSizeMessage<32>::FixedSizeMessage;
};

struct Signature: public FixedSizeMessage<64> {
  using FixedSizeMessage<64>::FixedSizeMessage;
};

/**
 * @brief Generates a keypair. Depends on randombytes.h random generator.
 * @param[out] sk allocated buffer of ed25519_privkey_SIZE
 * @param[out] pk allocated buffer of ed25519_pubkey_SIZE
 * @return false if failed, true otherwise
 */
ED25519_CPP_EXPORT bool create_keypair(PrivateKey& sk, PublicKey& pk);

/**
 * @brief Creates a public key from given private key. For every private key
 * there is exactly one possible public key.
 *
 * Use this method to create a keypair from given randomness.
 *
 * @param[in] sk allocated buffer of ed25519_privkey_SIZE
 * @param[out] pk allocated buffer of ed25519_pubkey_SIZE
 */
ED25519_CPP_EXPORT void derive_public_key(PrivateKeyView sk, PublicKey& pk);

/**
 * @brief Sign msg with keypair {pk, sk}
 * @param sig[out] signature
 * @param msg[in] message
 * @param sk[in] secret (private) key
 * @param pk[in] public key
 */
ED25519_CPP_EXPORT void sign(Signature& sig, MessageView msg, PrivateKeyView sk,
                             PublicKeyView pk);

/**
 * Verifies given sig over given msg with public key pk
 * @param sig[in] signature
 * @param msg[in] message
 * @param msglen[in] message size in bytes
 * @param pk[in] public key
 * @return true if signature is valid, false otherwise
 */
ED25519_CPP_EXPORT
bool verify(SignatureView sig, MessageView msg, PublicKeyView pk);

}  // namespace v2
}  // namespace iroha_ed25519

#endif  //  PROJECT_ED25519_HPP_
