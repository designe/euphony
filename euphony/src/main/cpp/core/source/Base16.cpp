#include "../Base16.h"
#include <sstream>
#include <iomanip>
#include <DefaultCharset.h>

string Euphony::Base16::encode(string src) {
    if(getCharset() == nullptr)
        setCharset(new DefaultCharset());

    return getCharset()->encode(src);
}

string Euphony::Base16::decode(string src) {
    if(getCharset() == nullptr)
        setCharset(new DefaultCharset());

    return getCharset()->decode(src);
}

int Euphony::Base16::convertChar2Int(char source) {
    switch(source) {
        case '0': case '1': case '2':
        case '3': case '4': case '5':
        case '6': case '7': case '8':
        case '9':
            return source - '0';
        case 'a': case 'b': case 'c':
        case 'd': case 'e': case 'f':
            return source - 'a' + 10;
        default:
            throw Base16Exception();
    }

    return -1;
}

