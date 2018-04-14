#ifndef STRUCTS_H
#define STRUCTS_H
#include "factorydepends.h"
#include "interfaces.h"
#include "astnodetype.h"
#include "json.hpp"

using json = nlohmann::json;

class Structs :public interfaces
{
public:
    json dataServer;
    dataServer["data"] = {{"inicio","vla"}};
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
        cout<<"nodo tipo:"<<node->Value<<endl;
        json dataServer;
        dataServer["type"] = "struct";
        dataServer["name"] = node->Left->value;
        dataServer["value"] = node->Right->Value;
        dataServer["size"] = 4;
        cout<<dataServer.dump()<<endl;
    }
    void Free() {
        delete this;
    }
    static interfaces* __stdcall Create(){
        return new Structs();
    }
};
#endif // STRUCTS_H
