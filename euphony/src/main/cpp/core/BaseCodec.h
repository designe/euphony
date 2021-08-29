#ifndef EUPHONY_BASECODEC_H
#define EUPHONY_BASECODEC_H

#include "Charset.h"
#include <string>
using std::string;

namespace Euphony {
    class BaseCodec {
        Charset* charset;
    public:
        virtual ~BaseCodec() = default;

        Charset* getCharset() {
            return charset;
        }

        void setCharset(Charset* charSet) {
            charset = charSet;
        }

        virtual string encode(string src) = 0;
        virtual string decode(string src) = 0;
        virtual int convertChar2Int(char src) = 0;
    };
}

#endif //EUPHONY_BASECODEC_H
