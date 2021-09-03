#ifndef EUPHONY_BASE16_H
#define EUPHONY_BASE16_H

#include "Base.h"
#include "Base16Exception.h"

namespace Euphony {

    class Base16 : public Base {
    public:
        Base16(const HexVector &hexVector);

        ~Base16() = default;
        string getBaseString();
        const HexVector &getHexVector() const;
        int convertChar2Int(char source);

    private:
        HexVector hexVector;
    };
}

#endif //EUPHONY_BASE16_H
