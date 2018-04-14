#ifndef STRINGS_H
#define STRINGS_H
#include "factorydepends.h"
#include "interfaces.h"
#include "astnodetype.h"
#include "json.hpp"

using json = nlohmann::json;
class Chars :public interfaces
{
public:
     void send(char* name,char* value) {
        cout<<"name: "<<name<<" value:"<<value<<endl;
    }

     void send(char* name, double value) {
         cout<<"name: "<<name<<" value:"<<value<<endl;
    }
     void print(){
         cout<<"name:pruebas na mas "<<endl;
    }
    void Data(ASTNodeType* node){
        cout<<"nodo tipo wohoo:"<<node->Value<<endl;
        json dataServer;
        dataServer["type"] = "Char";
        dataServer["name"] = node->Left->value;
        dataServer["value"] = node->Right->value;
        dataServer["size"] = 1;
        cout<<dataServer.dump()<<endl;
    }
    void Free() {
        delete this;
    }
    static interfaces* __stdcall Create(){
        return new Chars();
    }
};

#endif // STRINGS_H
