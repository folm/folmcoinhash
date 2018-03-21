{
    "targets": [
        {
            "target_name": "folmcoinhash",
            "sources": ["phi1612.c",
                      "sha3/skein.c",
                      "sha3/jh.c",
                      "sha3/cubehash.c",
                      "sha3/fugue.c",
                      "sha3/gost.c",
                      "sha3/echo.c",
                        "folmcoin-hash.cc"],
            "include_dirs" : [ 
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}
