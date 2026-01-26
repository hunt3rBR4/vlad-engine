#ifndef SECP256K1_H
#define SECP256K1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

/** Context flags */
#define SECP256K1_CONTEXT_NONE (1 << 0)
#define SECP256K1_CONTEXT_VERIFY (1 << 8)
#define SECP256K1_CONTEXT_SIGN (1 << 9)

typedef struct secp256k1_context_struct secp256k1_context;
typedef struct {
	uint8_t data[64];
} secp256k1_pubkey;
typedef struct {
	uint8_t data[32];
} secp256k1_keypair;

secp256k1_context *secp256k1_context_create(unsigned int flags);
void secp256k1_context_destroy(secp256k1_context *ctx);

int secp256k1_keypair_create(const secp256k1_context *ctx, secp256k1_keypair *keypair, const uint8_t *seckey);

#ifdef __cplusplus
}
#endif

#endif /* SECP256K1_H */
