{
    "targets": [
        {
            "target_name": "folmcoinhash",
            "sources": ["phi1612.c",
                      "sha3/sph_skein.h",
                      "sha3/sph_jh.h",
                      "sha3/sph_cubehash.h",
                      "sha3/sph_fugue.h",
                      "sha3/sph_gost.h",
                      "sha3/sph_echo.h",
                        "folmcoin-hash.cc"],
            "include_dirs" : [ 
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}
