#ifndef INFO
#define INFO

#include <iostream>
#include <string>

using namespace std;

class Info{
    string key;
    string value;
    public:
        Info(string name, string password){
            this->key = name;
            this->value = password;
        }

    string getKey(){
        return key;
    }

    string getValue(){
        return value;
    }
};

#endif
