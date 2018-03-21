
#ifndef PHI1612_H
#define PHI1612_H
#include "sha3/sph_skein.h"
#include "sha3/sph_jh.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_fugue.h"
#include "sha3/sph_gost.h"
#include "sha3/sph_echo.h"
#include "uint256.h"

#ifdef __cplusplus
extern "C" {
#endif

uint512_t phi1612_hash(const char* input, char* output);

#ifdef __cplusplus
}
#endif

#endif //PHI1612_H