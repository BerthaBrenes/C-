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
    cout<<"Valor de izquierda"<< Left->Value<<endl;
    cout<<"Valor de derecha"<< Right->Value<<endl;
    cout<<"Valor derecha char"<<Right->value<<endl;
    if(Left->value)
    {
        cout<<"Valor de izquierda"<<Left->value<<endl;
    }

}

void ASTNodeType::Print(ASTNodeType *root)
{

}
