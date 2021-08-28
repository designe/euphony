#ifndef EUPHONY_DEFAULTCHARSET_H
#define EUPHONY_DEFAULTCHARSET_H

#include "Charset.h"

namespace Euphony {

    class DefaultCharset : public Charset {
    public:
        DefaultCharset() = default;
        ~DefaultCharset() = default;
        string encode(string src);
        string decode(string src);
    };
}


#endif //EUPHONY_DEFAULTCHARSET_H
