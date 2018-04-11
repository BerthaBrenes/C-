#include "parseo.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "parseoascii.h"
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
        cout<<"Operador suma "<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expresion1();
        return CreateNode(OperadorPlus, e1node, tnode);
    case Reference:
        cout<<"Operador ref "<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expresion1();
        return CreateNode(OperatorRef,e1node,tnode);
    case Minus:
        cout<<"Operador Minus"<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expresion1();
        return CreateNode(OperadorMinus, e1node, tnode);
    case Variable:
        cout<<"Operador Variable"<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expresion1();
        return CreateNode(VariableValue, e1node,tnode);
    case Equal:
        cout<<"Operator Equal"<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expresion1();
        return CreateNode(OperadorEq, e1node,tnode);
    }

    return CreateNodeNumber(0);
}
void parseo::GetNextToken()
{
    cout<<"entra al token"<<endl;
    skipSpace();
    m_crtToken.Value = 0;
    m_crtToken.Symbol =0;
    if(m_Text[m_Index]==0){
        cout<<"primer if, index igual a 0"<<endl;
        m_crtToken.Type = EndOfText;
        return;
    }
    if(isdigit(m_Text[m_Index])){
        cout<<"encontro un numero"<<endl;
        m_crtToken.Type = Number;
        m_crtToken.Value = GetValue();
        cout<<"Valor del numero"<<m_crtToken.Value<<endl;
        return;
    }
    if(islower(m_Text[m_Index])){
        cout<<"encontro un operador"<<endl;
        m_crtToken.Type = Reference;
        m_crtToken.Value = GetReference();
        cout<<"valor"<<m_crtToken.Value<<endl;
        return;
    }
    if(isupper(m_Text[m_Index])){
        cout<<"Encontro un variable"<<endl;
        m_crtToken.Type = Variable;
        m_crtToken.Value = GetVariable();
        cout<<"valor"<<m_crtToken.Value<<endl;
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
    cout<<"Get number"<<endl;
    int index = m_Index;
    char buffer[32] = {0};
    int indice =0;
    while(isdigit(m_Text[m_Index])){
        buffer[indice] = m_Text[m_Index];
        cout<<"valor buffer"<<buffer[indice]<<endl;
        indice++;
        m_Index++;
    }
    if(m_Text[m_Index]== '.'){
        cout<<"if de punto"<<endl;
        m_Index++;
    }
    if(m_Index - index == 0){
        cout<<"Number expected but not found"<<m_Index<<endl;
    }
   // memcpy(buffer,&m_Text[m_Index], m_Index-index);
    double result = parseoascii().charToint(buffer);
    cout<<"valor buffer"<<result<<endl;
    return result;
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
    node->Type = UnaryMinus;
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






