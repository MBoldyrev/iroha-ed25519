#include "ed25519_cpp/ed25519.hpp"

#include <stddef.h>

#include "ed25519/ed25519.h"

using namespace iroha_ed25519::v2;

bool iroha_ed25519::v2::create_keypair(PrivateKey& sk, PublicKey& pk) {
  private_key_t* c_sk =
      reinterpret_cast<private_key_t*>(sk.data() - offsetof(private_key_t, data));
  public_key_t* c_pk =
      reinterpret_cast<public_key_t*>(pk.data() - offsetof(public_key_t, data));
  return ed25519_create_keypair(c_sk, c_pk) != 0;
}

void iroha_ed25519::v2::derive_public_key(PrivateKeyView sk, PublicKey& pk) {
  private_key_t const* c_sk = reinterpret_cast<private_key_t const*>(
      sk.data() - offsetof(private_key_t, data));
  public_key_t* c_pk =
      reinterpret_cast<public_key_t*>(pk.data() - offsetof(public_key_t, data));
  ed25519_derive_public_key(c_sk, c_pk);
}

void iroha_ed25519::v2::sign(Signature& sig, MessageView msg, PrivateKeyView sk,
                             PublicKeyView pk) {
  signature_t* c_sig =
      reinterpret_cast<signature_t*>(sig.data() - offsetof(signature_t, data));
  private_key_t const* c_sk = reinterpret_cast<private_key_t const*>(
      sk.data() - offsetof(private_key_t, data));
  public_key_t const* c_pk = reinterpret_cast<public_key_t const*>(
      pk.data() - offsetof(public_key_t, data));
  ed25519_sign(c_sig, msg.data(), msg.size(), c_pk, c_sk);
}

bool iroha_ed25519::v2::verify(SignatureView sig, MessageView msg,
                               PublicKeyView pk) {
  signature_t const* c_sig = reinterpret_cast<signature_t const*>(
      sig.data() - offsetof(signature_t, data));
  public_key_t const* c_pk = reinterpret_cast<public_key_t const*>(
      pk.data() - offsetof(public_key_t, data));
  return ed25519_verify(c_sig, msg.data(), msg.size(), c_pk);
}
