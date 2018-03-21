# folmcoinhash

Folmcoinhash is a Node.js native module for Folmcoin proof of work functions. It provides methods for Phi1612.

## Usage

    var folmcoinhash = require('folmcoinhash');

    var buf = Buffer.from('700000005d385ba114d079971b29a9418fd0549e7d68a95c7f168621a314201000000000578586d149fd07b22f3a8a347c516de7052f034d2b76ff68e0d6ecff9b77a45489e3fd511732011df0731000', 'hex');

    console.log(folmcoinhash.Phi1612(buf));
