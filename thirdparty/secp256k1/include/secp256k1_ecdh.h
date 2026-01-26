#ifndef SECP256K1_ECDH_H
#define SECP256K1_ECDH_H

#include "secp256k1.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*secp256k1_ecdh_hash_function)(
		uint8_t *output,
		const uint8_t *x32,
		const uint8_t *y32,
		void *data);

int secp256k1_ecdh(
		const secp256k1_context *ctx,
		uint8_t *output,
		const secp256k1_pubkey *pubkey,
		const uint8_t *privkey,
		secp256k1_ecdh_hash_function hashfp,
		void *data);

#ifdef __cplusplus
}
#endif

#endif /* SECP256K1_ECDH_H */
