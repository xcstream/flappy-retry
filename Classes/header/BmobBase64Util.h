

#ifndef __BmobSDK__BmobBase64Util__
#define __BmobSDK__BmobBase64Util__
#include <string>

class BmobBase64Util{
public:
    static std::string encode(std::string res, unsigned int len);
    static std::string decode(std::string const& s);
};

#endif
