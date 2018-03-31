#include "parseo.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

parseo::parseo()
{

}

parseo::parseo(const char *text)
{
    m_Text = text;
    m_Index = 0;
    cout<<"Constructor"<<text<<endl;
    Expresion();
    GetNextToken();

}
AstNode* parseo::Expresion()
{
    cout<<"estoy en la primer expresion"<<endl;
    AstNode* tnode = Term();
    AstNode* e1node = Expresion1();
    return CreateNode(OperadorPlus,tnode, e1node);
}

AstNode* parseo::Expresion1()
{
    AstNode* tnode;
    AstNode* e1node;
    switch(m_crtToken.Type){
    case Plus:
        cout<<"Operador plus en Expresion1"<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expresion1();
        return CreateNode(OperadorPlus, e1node,tnode);
     case Minus:
        cout<<"Operador minus encontrado en Expresion1"<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expresion1();
        return CreateNode(OperadorMinus, e1node, tnode);
    }
    return CreateNodeNumber(0);
}
void parseo::GetNextToken()
{
    cout<<"entra al token"<<endl;
    skipSpace();
    m_crtToken.Value = 0;
    m_crtToken.Symbol =0;
    if(m_Text[m_Index] ==  0){
        cout<<"No hay nada mas en la linea, es el final"<<endl;
        m_crtToken.Type = EnofText;
        return;
    }
    if(m_Text[m_Index] ==  ';'){
        cout<<"No hay nada mas en la linea, es el final"<<endl;
        m_crtToken.Type = EnofText;
        return;
    }
    if(isdigit(m_Text[m_Index])){
        cout<<"es un digito o valor"<<endl;
        m_crtToken.Type = Intiger;
        m_crtToken.Value = GetValue();
        cout<<"Indice donde se encontro el digito: "<<m_Index<<endl;
        m_Index++;
        return;
    }
    m_crtToken.Type = Error;
    switch(m_Text[m_Index]){
    case '+':
        m_crtToken.Type = Plus;
        cout<<"Tipo suma"<<endl;
        break;
    case '-':
        m_crtToken.Type = Minus;
        cout<<"Tipo Resta"<<endl;
        break;
    case '*':
        m_crtToken.Type = Mul;
        cout<<"Tipo Multiplicacion"<<endl;
        break;
    case '/':
        m_crtToken.Type = Div;
        cout<<"Tipo Division"<<endl;
        break;
    case '(':
        m_crtToken.Type = OpenParentesis;
        cout<<"Parentesis"<<endl;
        break;
    case ')':
        m_crtToken.Type = ClosedParentesis;
        cout<<"Cierre de parentesis"<<endl;
        break;
    case '{':
        m_crtToken.Type = OpenCorchete;
        cout<< "Corchete"<<endl;
        break;
    case '}':
        m_crtToken.Type = ClosedCorchete;
        cout<<"Cierre de corchete"<<endl;
        break;
    }
    if(m_crtToken.Type != Error){
        cout<<"No entra aqui, sube indice"<<endl;
        m_crtToken.Symbol = m_Text[m_Index];
        m_Index++;
        cout<<"Current indice"<<m_Index<<endl;
    }
    else{
        cout<<"Unexpected Token, error systax"<< m_Text[m_Index]<<"en la posicion"<<m_Index<<endl;

    }
}

double parseo::GetValue()
{
    skipSpace();
    int index = m_Index;
    while(isdigit(m_Text[m_Index])){
        m_Index++;
        cout<<"buscando donde no hayan digitos"<<endl;
    }
    if(m_Text[m_Index] == '.'){
        cout<<"hay un punto de value"<<endl;
        m_Index++;
    }
    if(m_Index - index == 0){
        cout<<"Number esperado no fue encontrado"<<endl;
    }
    char buffer[32] = {0};
    memcpy(buffer, &m_Text[m_Index],m_Index- index);
    cout<<"current index: "<<m_Index<<endl;
    return atof(buffer);
}
AstNode *parseo::Term()
{
    cout<<"estoy en el primer Term()"<<endl;
    AstNode* fnode = Factor();
    AstNode* t1node = Term1();
    return CreateNode(OperadorMul,fnode,t1node);
}



AstNode *parseo::Term1()
{
    AstNode* fnode;
    AstNode* t1node;
    switch(m_crtToken.Type){
    case Mul:
        GetNextToken();
        fnode = Factor();
        t1node = Term1();
        cout<<"Mi operador es un mul y creo un nodo"<<endl;
        return CreateNode(OperadorMul,t1node,fnode);
    case Div:
        GetNextToken();
        fnode = Factor();
        t1node = Term1();
        cout<<"Mi operador es plus y creo un nodo"<<endl;
        return CreateNode(OperadorDiv, t1node,fnode);

    }
    return CreateNodeNumber(1);
}

AstNode *parseo::Factor()
{
    AstNode* node;
    switch (m_crtToken.Type) {
    case OpenCorchete:
        GetNextToken();
        node = Expresion();
        Match('}');
        cout<<"Hay un corchete"<<endl;
        return node;
    case OpenParentesis:
        GetNextToken();
        node = Expresion();
        Match(')');
        cout<<"Hay un parentesis"<<endl;
        return node;
    case Minus:
        GetNextToken();
        node = Factor();
        cout<<"el parentesis tiene un menos"<<endl;
        return CreateUnaryNode(node);
   case Plus:
        GetNextToken();
        node = Factor();
        cout<<"hay una mas"<<endl;
        return CreateUnaryNode(node);
    case Number:{
        double value = m_crtToken.Value;
        GetNextToken();
        cout<<"Encontre el numero"<<endl;
        return CreateNodeNumber(value);
    }

    default:
    {
        cout<<"Un token no encontrado- "<<m_crtToken.Symbol<<"-en la posicion: "<< m_Index<<endl;

     }
   }
}

void parseo::Match(char expected)
{
    if(m_Text[m_Index-1] == expected){
        GetNextToken();
    }
    else{
        cout<<"Expected Token: "<<expected<<" at position: "<<m_Index<<endl;
    }
}

AstNode *parseo::CreateNode(NodeType type, AstNode *left, AstNode *right)
{
 AstNode* node = new AstNode;
 node->Type = type;
 node->Left = left;
 node->Right = right;
 cout<<"creo un nodo completo el nodo es de tipo"<<node->Type<<endl;
 return node;
}

AstNode *parseo::CreateUnaryNode(AstNode *left)
{
    cout<<"creo el nodo libre"<<endl;
    AstNode* node = new AstNode;
    node->Type = UniryMinus;
    node->Left = left;
    node->Right = nullptr;
    return node;
}

AstNode *parseo::CreateNodeNumber(double value)
{
    AstNode* node = new AstNode;
    cout<<"Nodo hoja"<<endl;
    node->Type = NumberValue;
    node->Value = value;
    return node;
}

void parseo::skipSpace()
{
    while(isspace(m_Text[m_Index])){
        cout<<"Espacios en blanco: "<<m_Index<<endl;
        m_Index++;
    }
}






