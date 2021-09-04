#include "../Packet.h"
#include "../PacketErrorDetector.h"
#include <sstream>
using namespace Euphony;


Packet::Packet(const HexVector& source) {
    payload = new Base16(source);
    initialize();
}


void Packet::initialize() {
    string errorCode = PacketErrorDetector::makeParityAndChecksum(payload->getBaseString());
    this->checksum = payload->convertChar2Int(errorCode.at(0));
    this->parityCode = payload->convertChar2Int(errorCode.at(1));
    this->isVerified = true;
}

void Packet::clear() {
    this->checksum = -1;
    this->parityCode = -1;
    this->isVerified = false;
    delete payload;
    payload = nullptr;
}

string Packet::getPayloadStr() const {
    return payload->getBaseString();
}

string Packet::toString() {
    std::stringstream result;

    result << "S" <<
    payload->getBaseString() <<
    getChecksum() <<
    getParityCode();

    return result.str();
}

void Packet::setPayload(Base* payloadSrc) {
    if(payload != nullptr) {
        delete payload;
        payload = nullptr;
    }

    payload = payloadSrc;
    initialize();
}

int8_t Packet::getChecksum() {
    return payload->convertInt2Char(checksum);
}

int8_t Packet::getParityCode() {
    return payload->convertInt2Char(parityCode);
}
