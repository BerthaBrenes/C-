#include "astnodetype.h"
#include <iostream>
using namespace std;
ASTNodeType::ASTNodeType()
{
    Type = Undefined;
    Value = 0;
    Left = nullptr;
    Right = nullptr;
}
void ASTNodeType::Print(){
    cout<<"Valor raiz"<< Value<<endl;
       cout<<"Valor del tipo"<< Type<<endl;
       cout<<"Valor de izquierda"<< Left->Value<<endl;
       cout<<'aqui se escpicha'<<endl;
       if(Right->Value)
       {
           cout<<"Valor de derecha"<< Right->Value<<endl;

       }
       if(Right->value)
       {
           cout<<"Valor derecha char: "<<Right->value<<endl;

       }
       if(Left->value)
       {
           cout<<"Valor de izquierda"<<Left->value<<endl;
       }

}
void ASTNodeType::Print(ASTNodeType* root){

}
