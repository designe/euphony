#ifndef EUPHONY_CHARSET_H
#define EUPHONY_CHARSET_H

#include <string>
using std::string;

namespace Euphony {
    class Charset {
    public:
        virtual ~Charset() = default;

        virtual string encode(string src) = 0;
        virtual string decode(string src) = 0;
    };
}
#endif //EUPHONY_CHARSET_H
