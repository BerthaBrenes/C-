#include "astnodetype.h"
#include <iostream>
#include <stdio.h>

using namespace std;
ASTNodeType::ASTNodeType()
{
    Type = Undefined;
    Value =0;
    Left = nullptr;
    Right = nullptr;
}

void ASTNodeType::Print()
{
    cout<<"Valor raiz"<< Value<<endl;
    if(Left->Value){
        cout<<"Valor de izquierda"<< Left->Value<<endl;
    }
    if(Right->Value){
        cout<<"Valor de derecha"<< Right->Value<<endl;
    }
    if(Right->value){
        cout<<"Valor de dereche"<<Right->value<<endl;
    }
}

void ASTNodeType::Print(ASTNodeType *root)
{

}
