#ifndef STRINGS_H
#define STRINGS_H
#include "factorydepends.h"
#include "interfaces.h"
#include "astnodetype.h"
#include "json.hpp"
#include "fstream"
#include "client.h"
using json = nlohmann::json;
class Chars :public interfaces
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
         cout<<"nam chars "<<endl;
    }

    ASTNodeType* Data(ASTNodeType* node){
        cout<<"nodo tipo wohoo:"<<node->Value<<endl;
        json dataServer;
        dataServer["type"] = "Char";
        dataServer["name"] = node->Left->value;
        dataServer["value"] = node->Right->value;
        dataServer["size"] = 1;
        cout<<dataServer.dump()<<endl;
        tcp.setPort(node->puerto);
        node->data = tcp.Execute(dataServer.dump());
        cout<<node->data<<endl;
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
        dataServer["type"] = "Char";
        dataServer["name"] = node->Left->value;
        dataServer["value"] = node->Right->value;
        dataServer["size"] = 1;
        cout<<dataServer.dump()<<endl;
        es<<dataServer<<endl;
        es.close();
    }
    static interfaces* Create(){
        return new Chars();
    }
};

#endif // STRINGS_H
