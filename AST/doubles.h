#ifndef DOUBLES_H
#define DOUBLES_H
#include "factorydepends.h"
#include "interfaces.h"
#include "astnodetype.h"
#include "json.hpp"
#include "fstream"

using json = nlohmann::json;
class doubles: public interfaces
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
         dataServer["type"] = "Double";
         dataServer["name"] = node->Left->value;
         dataServer["value"] = node->Right->Value;
         dataServer["size"] = 8;
         cout<<dataServer.dump()<<endl;
     }
     virtual void saveStruct(ASTNodeType* node){
         ofstream es;
         es.open("prueba.json",ios::app);
         cout<<"nodo tipo en struct:"<<node->Value<<endl;
         json dataServer;
         dataServer["type"] = "double";
         dataServer["name"] = node->Left->value;
         dataServer["value"] = node->Right->Value;
         dataServer["size"] = 1;
         cout<<dataServer.dump()<<endl;
         es<<dataServer<<endl;
         es.close();
     }
    void Free() {
        delete this;
    }
    static interfaces* __stdcall Create(){
        return new doubles();
    }
};

#endif // DOUBLES_H
