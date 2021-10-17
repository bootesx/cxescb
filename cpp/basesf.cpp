#include "basesf.h"

char* base64::encode(const char* str, int str_len)
{
    long len;  
    char *res;  
    int i,j;  
    char *table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";  

    if(str_len % 3 == 0)  
        len=str_len/3*4;  
    else  
        len=(str_len/3+1)*4;  

    res = (char*)malloc(sizeof(char)*len+1);  
    res[len]=0;  

    for(i=0,j=0; i<len-2; j+=3,i+=4)  
    {  
        res[i]=table[str[j]>>2];
        res[i+1]=table[(str[j]&0x3)<<4 | (str[j+1]>>4)];
        res[i+2]=table[(str[j+1]&0xf)<<2 | (str[j+2]>>6)];
        res[i+3]=table[str[j+2]&0x3f];
    }  

    switch(str_len%3)  
    {  
        case 1:  
            res[i-2]='=';  
            res[i-1]='=';  
            break;  
        case 2:  
            res[i-1]='=';  
            break;  
    }  
    
    return res;
}
    
char* base64::encode(const char* str)
{
    return encode(str, strlen(str));
}
    
char* base64::encode(string str)
{
    return encode(str.c_str());
}
    
char* base64::encode(string str, int str_len)
{
    return encode(str.c_str(), str_len);
}

char* base64::decode(const char* code)
{
    char table[] = {
        0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,62,0,0,0,
        63,52,53,54,55,56,57,58,
        59,60,61,0,0,0,0,0,0,0,0,
        1,2,3,4,5,6,7,8,9,10,11,12,
        13,14,15,16,17,18,19,20,21,
        22,23,24,25,0,0,0,0,0,0,26,
        27,28,29,30,31,32,33,34,35,
        36,37,38,39,40,41,42,43,44,
        45,46,47,48,49,50,51
    };
    long len;  
    long str_len;  
    char *res;  
    int i,j;  

    len = strlen(code);  

    if(strstr(code, "=="))
        str_len = len/4*3-2;  
    else if(strstr(code, "="))  
        str_len = len/4*3-1;  
    else  
        str_len = len/4*3;  

    res = (char*)malloc(sizeof(char)*str_len+1);  
    res[str_len] = 0;  
    
    for(i=0,j=0; i<len-2; j+=3,i+=4)  
    {  
        res[j] = ((char)table[code[i]])<<2 | (((char)table[code[i+1]])>>4); //取出第一个字符对应base64表的十进制数的前6位与第二个字符对应base64表的十进制数的后2位进行组合  
        res[j+1] = (((char)table[code[i+1]])<<4) | (((char)table[code[i+2]])>>2); //取出第二个字符对应base64表的十进制数的后4位与第三个字符对应bas464表的十进制数的后4位进行组合  
        res[j+2] = (((char)table[code[i+2]])<<6) | ((char)table[code[i+3]]);
    }
    return res;
}

char* base64::decode(string code)
{
    return decode(code.c_str());
}

char* base64::fencode(const char* path)
{
    string str;
    string line;
    ifstream myfile(path);
    if (!myfile.is_open())
        cout << "error!" << endl;
    while(getline(myfile, line))
    {
        str += line;
        str += "\n";
    }
    str.erase(str.size()-1);
    myfile.close();
    return encode(str, str.size());
}

char* base64::fencode(string path)
{
    return fencode(path.c_str());
}

char* base64::fdecode(const char* path)
{
    string code;
    ifstream myfile(path);
    if (!myfile.is_open())
        cout << "error!" << endl;
    myfile >> code;
    myfile.close();
    return decode(code);
}

char* base64::fdecode(string path)
{
    return fdecode(path.c_str());
}