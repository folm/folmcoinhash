// Copyright (c) 2009-2010 Satoshi Nakamoto                     -*- c++ -*-
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_HASH_H
#define BITCOIN_HASH_H

#include "sha3/ripemd160.h"
#include "sha3/sha256.h"
#include "uint256.h"


// Initilised PHI
#include "sha3/sph_skein.h"
#include "sha3/sph_jh.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_fugue.h"
#include "sha3/sph_gost.h"
#include "sha3/sph_echo.h"

#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

/** A hasher class for Bitcoin's 256-bit hash (double SHA-256). */

/* ----------- Phi1612 Hash ------------------------------------------------ */

template<typename T1>
inline uint256 Phi1612(const T1 pbegin, const T1 pend)
{
    sph_skein512_context     ctx_skein;
    sph_jh512_context ctx_jh;
    sph_cubehash512_context   ctx_cubehash;
    sph_fugue512_context      ctx_fugue;
    sph_gost512_context      ctx_gost;
    sph_echo512_context ctx_echo;
    static unsigned char pblank[1];

#ifndef QT_NO_DEBUG
    //std::string strhash;
    //strhash = "";
#endif

    uint512 hash[17];

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
    sph_skein512_close(&ctx_skein, static_cast<void*>(&hash[0]));

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, static_cast<const void*>(&hash[0]), 64);
    sph_jh512_close(&ctx_jh, static_cast<void*>(&hash[1]));

    sph_cubehash512_init(&ctx_cubehash);
    sph_cubehash512 (&ctx_cubehash, static_cast<const void*>(&hash[1]), 64);
    sph_cubehash512_close(&ctx_cubehash, static_cast<void*>(&hash[2]));

    sph_fugue512_init(&ctx_fugue);
    sph_fugue512 (&ctx_fugue, static_cast<const void*>(&hash[2]), 64);
    sph_fugue512_close(&ctx_fugue, static_cast<void*>(&hash[3]));

    sph_gost512_init(&ctx_gost);
    sph_gost512 (&ctx_gost, static_cast<const void*>(&hash[3]), 64);
    sph_gost512_close(&ctx_gost, static_cast<void*>(&hash[4]));

    sph_echo512_init(&ctx_echo);
    sph_echo512 (&ctx_echo, static_cast<const void*>(&hash[4]), 64);
    sph_echo512_close(&ctx_echo, static_cast<void*>(&hash[5]));

    return hash[5].trim256();
}



#endif // BITCOIN_HASH_H