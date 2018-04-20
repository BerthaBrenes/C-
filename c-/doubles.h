#ifndef DOUBLES_H
#define DOUBLES_H
#include "factorydepends.h"
#include "interfaces.h"
#include "astnode.h"
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
         cout<<"name:double "<<endl;
    }
     astNode* Data(astNode* node){
         cout<<"nodo tipo wohoo:"<<node->Value<<endl;
         json dataServer;
         dataServer["type"] = "Double";
         dataServer["name"] = node->Left->value;
         dataServer["value"] = node->Right->Value;
         dataServer["size"] = 8;
         cout<<dataServer.dump()<<endl;
        return node;
     }
     virtual void saveStruct(astNode* node){
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
    static interfaces* Create(){
        return new doubles();
    }
};

#endif // DOUBLES_H
