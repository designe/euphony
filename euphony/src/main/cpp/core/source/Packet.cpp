#include "../Packet.h"
#include "../PacketErrorDetector.h"
#include <sstream>
using namespace Euphony;


Packet::Packet(const HexVector& source) {
    payload = new Base16(source);
    initialize();
}


void Packet::initialize() {
    string errorCode = PacketErrorDetector::makeParityAndChecksum(payload->getHexVector());
    this->checksum = payload->convertChar2Int(errorCode.at(0));
    this->parityCode = payload->convertChar2Int(errorCode.at(1));

}

void Packet::clear() {
    this->checksum = -1;
    this->parityCode = -1;
    this->isVerified = false;
    delete payload;
}

string Packet::getPayloadStr() const {
    return payload->getBaseString();
}

string Packet::toString() {
    std::stringstream result;

    result << "S";
    for(auto data : payload->getBaseString()) {
        result << std::hex << data;
    }

    result << std::to_string(checksum) << std::to_string(parityCode);

    return result.str();
}

void Packet::setPayload(Base *payload) {
    if(Packet::payload != nullptr)
        delete Packet::payload;

    Packet::payload = payload;
}
