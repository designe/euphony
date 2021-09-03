#ifndef EUPHONY_BASE_H
#define EUPHONY_BASE_H

#include "Charset.h"
#include <string>
using std::string;

namespace Euphony {
    class Base {
    public:
        virtual ~Base() = default;

        virtual string getBaseString() = 0;
        virtual const HexVector &getHexVector() const = 0;
        virtual int convertChar2Int(char src) = 0;
    };
}

#endif //EUPHONY_BASE_H
