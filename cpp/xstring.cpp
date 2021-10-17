#include "xstring.h"

xstring::xstring():string()
{
}

xstring::xstring(const char* str):string(str)
{
}

xstring::xstring(const string& str):string(str)
{
}
        
xstring::xstring(const xstring& str):string(str)
{
}
        
xstring xstring::b64encode()
{
    const char* es = encode(c_str());
    xstring a(es);
    return a;
}
        
xstring xstring::b64decode()
{
    const char* ds = decode(c_str());
    xstring a(ds);
    return a;
}