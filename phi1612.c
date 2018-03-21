#include "phi1612.h"

// Initilised PHI
#include "sha3/sph_skein.h"
#include "sha3/sph_jh.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_fugue.h"
#include "sha3/sph_gost.h"
#include "sha3/sph_echo.h"
#include "uint256.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>


void phi1612_hash(const char* input, char* output)
{
    sph_skein512_context     ctx_skein;
    sph_jh512_context ctx_jh;
    sph_cubehash512_context   ctx_cubehash;
    sph_fugue512_context      ctx_fugue;
    sph_gost512_context      ctx_gost;
    sph_echo512_context ctx_echo;

    uint32_t hash[17];

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, input,64);
    sph_skein512_close(&ctx_skein, &hash[0]);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, &hash[0], 64);
    sph_jh512_close(&ctx_jh, &hash[1]);

    sph_cubehash512_init(&ctx_cubehash);
    sph_cubehash512 (&ctx_cubehash, &hash[1], 64);
    sph_cubehash512_close(&ctx_cubehash, &hash[2]);

    sph_fugue512_init(&ctx_fugue);
    sph_fugue512 (&ctx_fugue, &hash[2], 64);
    sph_fugue512_close(&ctx_fugue, &hash[3]);

    sph_gost512_init(&ctx_gost);
    sph_gost512 (&ctx_gost, &hash[3], 64);
    sph_gost512_close(&ctx_gost,&hash[4]);

    sph_echo512_init(&ctx_echo);
    sph_echo512 (&ctx_echo, &hash[4], 64);
    sph_echo512_close(&ctx_echo, &hash[5]);

    memcpy(output, &hash[5], 64);
}

