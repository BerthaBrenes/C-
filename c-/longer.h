#ifndef LONGER_H
#define LONGER_H
#include "factorydepends.h"
#include "interfaces.h"
#include "astnode.h"
#include "json.hpp"
#include "fstream"

using json = nlohmann::json;
class Longer :public interfaces
{
public:
     void send(char* name,char* value) {
        cout<<"name: "<<name<<" value:"<<value<<endl;
    }

     void send(char* name, double value) {
         cout<<"name: "<<name<<" value:"<<value<<endl;
    }
     void print(){
         cout<<"name:prlonger "<<endl;
    }
    void Data(astNode* node){
        cout<<"nodo tipo:"<<node->Value<<endl;
        json dataServer;
        dataServer["type"] = "long";
        dataServer["name"] = node->Left->value;
        dataServer["value"] = node->Right->Value;
        dataServer["size"] = 8;
        cout<<dataServer.dump()<<endl;
    }
    void Free() {
        delete this;
    }
    virtual void saveStruct(astNode* node){
        ofstream es;
        es.open("prueba.json",ios::app);
        cout<<"nodo tipo en struct:"<<node->Value<<endl;
        json dataServer;
        dataServer["type"] = "long";
        dataServer["name"] = node->Left->value;
        dataServer["value"] = node->Right->Value;
        dataServer["size"] = 1;
        cout<<dataServer.dump()<<endl;
        es<<dataServer<<endl;
        es.close();
    }
    static interfaces* Create(){
        return new Longer();
    }
};
#endif // LONGER_H
