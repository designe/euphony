#include "../ASCIICharset.h"
#include <sstream>
#include <iomanip>

string Euphony::ASCIICharset::encode(string src) {
    std::ostringstream result;
    result << std::setw(2) << std::setfill('0') << std::hex;
    std::copy(src.begin(), src.end(), std::ostream_iterator<unsigned int>(result, ""));
    return result.str();
}

string Euphony::ASCIICharset::decode(string src) {
    string result = "";

    for(int i = 0; i < src.length() - 1; i+=2) {
        string c = src.substr(i, 2);
        result.push_back((char) (int) strtol(c.c_str(), nullptr, 16));
    }

    return result;
}
