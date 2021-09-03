#ifndef EUPHONY_BASE2_H
#define EUPHONY_BASE2_H

namespace Euphony {

    class Base2 : public BaseCodec {
    public:
        Base2() = default;
        ~Base2() = default;
        string encode(string src);
        string decode(string src);
        int convertChar2Int(char source);
    };
}

#endif //EUPHONY_BASE2_H
