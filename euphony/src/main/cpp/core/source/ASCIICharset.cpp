#include "../ASCIICharset.h"
#include <sstream>
#include <iomanip>

using namespace Euphony;

HexVector ASCIICharset::encode(std::string src) {
    HexVector result(src.size());

    for(char &c : src) {
        result.pushBack(c);
    }

    return result;
}

std::string ASCIICharset::decode(const HexVector &src) {
    std::string result = "";

    for(auto hexData : src) {
        result.push_back(hexData);
    }
    /*
    for(int i = 0; i < src.getSize() - 1; i+=2) {
        std::string c = src.substr(i, 2);
        result.push_back((char) (int) strtol(c.c_str(), nullptr, 16));
    }*/

    return result;
}
