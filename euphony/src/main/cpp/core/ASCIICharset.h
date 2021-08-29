#ifndef EUPHONY_ASCIICHARSET_H
#define EUPHONY_ASCIICHARSET_H

#include "Charset.h"

namespace Euphony {

    class ASCIICharset : public Charset {
    public:
        ASCIICharset() = default;
        ~ASCIICharset() = default;
        string encode(string src);
        string decode(string src);
    };
}

#endif //EUPHONY_ASCIICHARSET_H
