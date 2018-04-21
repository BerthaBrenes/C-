#ifndef STRUCTS_H
#define STRUCTS_H
#include "factorydepends.h"
#include "interfaces.h"
#include "astnodetype.h"
#include "json.hpp"
#include "fstream"
#include "client.h"

using json = nlohmann::json;

class Structs :public interfaces
{
public:
    client tcp;
    //json dataServer;
    //dataServer["data"] = {{"inicio","vla"}};
     void send(char* name,char* value) {
        cout<<"name: "<<name<<" value:"<<value<<endl;
    }

     void send(char* name, double value) {
         cout<<"name: "<<name<<" value:"<<value<<endl;
    }
     void print(){
         cout<<"se supone que estoy en struct "<<endl;
    }

    ASTNodeType* Data(ASTNodeType* node){
        json dataServer;
        dataServer["type"] = "struct";
        dataServer["label"] = node->Left->value;
        dataServer["size"] = 2;
        char cadena[128];
        ifstream ls;
        ls.open("prueba.json",ios::in);
        while(!ls.eof()) {
           ls >> cadena;
           dataServer["value"].operator +=(cadena);
        }
        ls.close();
        ofstream esf;
        esf.open("prueba.json",ios::out |ios::trunc);
        esf.close();
        cout<<"nodo tipo:"<<node->Value<<endl;
        cout<<dataServer<<endl;
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
        cout<<"aqui deberia tan siquiera entrar"<<endl;

    }
    static interfaces* Create(){
        return new Structs();
    }
};
#endif // STRUCTS_H
