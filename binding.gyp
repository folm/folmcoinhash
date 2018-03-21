{
    "targets": [
        {
            "target_name": "folmcoinhash",
            "sources": ["phi1612.c",
                      "sha3/sph_skein.c",
                      "sha3/sph_jh.c",
                      "sha3/sph_cubehash.c",
                      "sha3/sph_fugue.c",
                      "sha3/sph_gost.c",
                      "sha3/sph_echo.c",
                        "folmcoin-hash.cc"],
            "include_dirs" : [ 
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}
