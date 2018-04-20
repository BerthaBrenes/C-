#include "astnode.h"
#include <iostream>

using namespace std;
astNode::astNode()
{
 Type = Undefined;
 Value = 0;
 Left = nullptr;
 Right = nullptr;
}

void astNode::Print()
{
    cout<<"Valor raiz"<< Value<<endl;
       cout<<"Valor de izquierda"<< Left->Value<<endl;
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
