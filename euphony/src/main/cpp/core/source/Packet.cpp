#include "../Packet.h"
#include "../PacketErrorDetector.h"
#include "../BaseFactory.h"
#include <sstream>
using namespace Euphony;

Packet::Packet(const HexVector& source)
        : baseType(BaseType::BASE16),
          payload(nullptr),
          checksum(-1),
          parityCode(-1),
          isVerified(false) {
    payload = BaseFactory::create(baseType, source);
    initialize();
}

Packet::Packet(const BaseType baseTypeSrc, const HexVector& source)
: baseType(baseTypeSrc),
  payload(nullptr),
  checksum(-1),
  parityCode(-1),
  isVerified(false) {
    payload = BaseFactory::create(baseTypeSrc, source);
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
    //delete payload;
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

void Packet::setPayload(std::shared_ptr<Base> payloadSrc) {
    payload = std::move(payloadSrc);
    initialize();
}


void Packet::setPayload(const HexVector &source) {
    payload = BaseFactory::create(baseType, source);
    initialize();
}

u_int8_t Packet::getChecksum() {
    return payload->convertInt2Char(checksum);
}

u_int8_t Packet::getParityCode() {
    return payload->convertInt2Char(parityCode);
}

