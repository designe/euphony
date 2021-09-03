#include "../Base16.h"
#include <sstream>
#include <iomanip>

using namespace Euphony;

Base16::Base16(const HexVector &hexVector) : hexVector(hexVector) { }

string Base16::getBaseString() {
    return hexVector.toString();
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

const Euphony::HexVector &Euphony::Base16::getHexVector() const {
    return hexVector;
}



