#ifndef LONGER_H
#define LONGER_H
#include "factorydepends.h"
#include "interfaces.h"
#include "astnodetype.h"
#include "json.hpp"
#include "fstream"
#include "client.h"

using json = nlohmann::json;
class Longer :public interfaces
{
public:
    client tcp;
     void send(char* name,char* value) {
        cout<<"name: "<<name<<" value:"<<value<<endl;
    }

     void send(char* name, double value) {
         cout<<"name: "<<name<<" value:"<<value<<endl;
    }
     void print(){
         cout<<"name:prlonger "<<endl;
    }

    ASTNodeType* Data(ASTNodeType* node){
        cout<<"nodo tipo:"<<node->Value<<endl;
        json dataServer;
        dataServer["type"] = "long";
        dataServer["label"] = node->Left->value;
        dataServer["value"] = node->Right->Value;
        dataServer["size"] = 8;
        cout<<dataServer.dump()<<endl;
        tcp.setPort(node->puerto);
        node->data = tcp.Execute(dataServer.dump());
        cout<<node->data<<endl;
        ofstream es;
        es.open("table.json",ios::out);
        es<<node->data<<endl;
        es.close();
        return node;

    }
    void Free() {
        delete this;
    }
    virtual void saveStruct(ASTNodeType* node){
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
