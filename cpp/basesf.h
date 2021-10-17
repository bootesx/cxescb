#ifndef BASESF_H
#define BASESF_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class base64
{  
public:
    char* encode(const char* str, int str_len);
    
    char* encode(const char* str);

    char* encode(string str);
    
    char* encode(string str, int str_len);
    
    char* decode(const char* code);
    
    char* decode(string code);
    
    char* fencode(const char* path);
    
    char* fencode(string path);
    
    char* fdecode(const char* path);
    
    char* fdecode(string path);
};

#endif