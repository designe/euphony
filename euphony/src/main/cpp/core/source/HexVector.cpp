#include "../HexVector.h"
#include <string>
#include <sstream>

using namespace Euphony;

HexVector::HexVector(int size) {
    hexSource.reserve(size);
}

HexVector::HexVector(const HexVector &copy) {
    setHexSource(copy.getHexSource());
}

HexVector::HexVector(const std::string hexString) {
    for(int i = 0; i < hexString.length() - 1; i += 2) {
        std::string c = hexString.substr(i, 2);
        hexSource.push_back(strtol(c.c_str(), nullptr, 16));
    }
}

HexVector::HexVector(const std::vector<int8_t> &hexVectorCopy) {
    setHexSource(hexVectorCopy);
}


HexVector::~HexVector() {
    hexSource.clear();
}

void HexVector::pushBack(int8_t hexByte) {
    hexSource.push_back(hexByte);
}

void HexVector::popBack() {
    hexSource.pop_back();
}

std::string HexVector::toString() const{
    std::stringstream result;

    for(auto data : hexSource) {
        result << std::hex << (int) data;
    }

    return result.str();
}

const std::vector<int8_t> &HexVector::getHexSource() const {
    return hexSource;
}

void HexVector::setHexSource(const std::vector<int8_t> &hexSource) {
    HexVector::hexSource.clear();
    HexVector::hexSource.assign(hexSource.begin(), hexSource.end());
}

int HexVector::getSize() const {
    return hexSource.size();
}

std::__wrap_iter<std::vector<signed char, std::allocator<signed char>>::const_pointer> HexVector::begin() const{
    return hexSource.begin();
}

std::__wrap_iter<std::vector<signed char, std::allocator<signed char>>::const_pointer> HexVector::end() const{
    return hexSource.end();
}

void HexVector::clear(){
    hexSource.clear();
}
