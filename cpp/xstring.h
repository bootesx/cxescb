#ifndef XSTRING_H
#define XSTRING_H

#include <iostream>
#include <string>
#include "basesf.h"

using namespace std;

class xstring : public string, private base64
{
    public:
        xstring();
        xstring(const char* str);
        xstring(const string& str);
        xstring(const xstring& str);
        xstring b64encode();
        xstring b64decode();
};

#endif