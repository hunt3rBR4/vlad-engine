#ifndef SECP256K1_SCHNORRSIG_H
#define SECP256K1_SCHNORRSIG_H

#include "secp256k1.h"

#ifdef __cplusplus
extern "C" {
#endif

int secp256k1_schnorrsig_sign32(const secp256k1_context *ctx, uint8_t *sig64, const uint8_t *msg32, const secp256k1_keypair *keypair, const uint8_t *aux_rand32);

#ifdef __cplusplus
}
#endif

#endif /* SECP256K1_SCHNORRSIG_H */
