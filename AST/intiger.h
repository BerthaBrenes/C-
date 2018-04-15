#ifndef INTIGER_H
#define INTIGER_H
#include "factorydepends.h"
#include "interfaces.h"
#include "astnodetype.h"
#include "json.hpp"
#include "fstream"
using json = nlohmann::json;
class Intiger :public interfaces
{
public:
     void send(char* name,char* value) {
        cout<<"name: "<<name<<" value:"<<value<<endl;
    }

     void send(char* name, double value) {
         cout<<"name: "<<name<<" value:"<<value<<endl;
    }
     void print(){
         cout<<"name:prsdunts int "<<endl;
    }
    void Data(ASTNodeType* node){
        cout<<"nodo tipo:"<<node->Value<<endl;
        json dataServer;
        dataServer["type"] = "int";
        dataServer["name"] = node->Left->value;
        dataServer["value"] = node->Right->Value;
        dataServer["size"] = 4;
        cout<<dataServer.dump()<<endl;
    }
    void Free() {
        delete this;
    }
    virtual void saveStruct(ASTNodeType* node){
        ofstream es;
        es.open("prueba.json",ios::app);
        cout<<"nodo tipo en struct:"<<node->Value<<endl;
        json dataServer;
        dataServer["type"] = "int";
        dataServer["name"] = node->Left->value;
        dataServer["value"] = node->Right->Value;
        dataServer["size"] = 1;
        cout<<dataServer.dump()<<endl;
        es<<dataServer<<endl;
        es.close();
    }
    static interfaces* __stdcall Create(){
        return new Intiger();
    }
};
#endif // INTIGER_H
