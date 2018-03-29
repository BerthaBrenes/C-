#include "prefix.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <parserexception.h>
using namespace std;


prefix::prefix(const char *text)
{
   m_Text = text;
   m_Index = 0;
   cout<<"constructor"<<endl;
   GetNextToken();

   Expression();
}

prefix::prefix()
{

}

ASTNodeType* prefix::Expression()
{
    ASTNodeType* tnode = Term();
    ASTNodeType* e1node = Expression1();
    return CreateNode(OperatorPlus, tnode, e1node);
}

void prefix::SkipWhiteSpaces()
{
    while(isspace(m_Text[m_Index])){
        cout<<"whitespace, index "<<endl;
        m_Index++;
    }
}
ASTNodeType* prefix::Expression1(){
    ASTNodeType* tnode;
    ASTNodeType* e1node;

    switch (m_crtToken.Type) {
    case Plus:
        GetNextToken();
        tnode = Term();
        e1node = Expression1();
        return CreateNode(OperatorPlus, e1node, tnode);

    case Minus:
        GetNextToken();
        tnode = Term();
        e1node = Expression1();
        return CreateNode(OperatorMinus, e1node, tnode);
    }
    return CreateNodeNumber(0);
}

void prefix::GetNextToken()
{
   SkipWhiteSpaces();
   m_crtToken.Value = 0;
   m_crtToken.Symbol = 0;
   cout<< "Get next token"<<endl;
   if(m_Text[m_Index]==0){
       cout<<"primer if, index igual a 0"<<endl;
       m_crtToken.Type = EndOfText;
       return;
   }
   if(isdigit(m_Text[m_Index])){
       cout<<"segundo if"<<endl;
       m_crtToken.Type = Number;
       m_crtToken.Value = GetNumber();
       return;
   }
   m_crtToken.Type = Error;
   switch (m_Text[m_Index]) {
   case '+':
       m_crtToken.Type = Plus;
       cout<<"plus"<<endl;
       break;
   case '-':
       m_crtToken.Type = Minus;
       cout<<"minus"<<endl;
       break;
   case '*':
       m_crtToken.Type = Mul;
       cout<<"mul"<<endl;
       break;
   case '/':
       m_crtToken.Type = Div;
       break;
   case '(':
       m_crtToken.Type = OpenParentesis;
       break;
   case ')':
       m_crtToken.Type = ClosedParentesis;
       break;
   }
   if(m_crtToken.Type != Error){
       m_crtToken.Symbol = m_Text[m_Index];
       m_Index++;
   }
   else{

       cout<< "Unexpected token "<<m_Text[m_Index]<< " at position "<< m_Index<< endl;
   }
}

double prefix::GetNumber()
{
    SkipWhiteSpaces();
    cout<<"Get number"<<endl;
    int index = m_Index;
    while(isdigit(m_Text[m_Index])){
        m_Index++;
        cout<<"while numbrt"<<endl;
    }
    if(m_Text[m_Index]== '.'){
      cout<<"if de punto"<<endl;
      m_Index++;
    }
    if(m_Index - index == 0){
       cout<<"Number expected but not found"<<m_Index<<endl;
    }
    char buffer[32] = {0};
    memcpy(buffer,&m_Text[m_Index], m_Index- index);

    return atof(buffer);
}

ASTNodeType *prefix::Term()
{
    ASTNodeType* fnode = Factor();
    ASTNodeType* t1node = Term1();
    return CreateNode(OperatorMul, fnode, t1node);
}

ASTNodeType *prefix::Term1()
{
    ASTNodeType* fnode;
    ASTNodeType* t1node;
    switch(m_crtToken.Type){
    case Mul:
        GetNextToken();
        fnode =Factor();
        t1node = Term1();
        return CreateNode(OperatorMul,t1node,fnode);

    case Div:
        GetNextToken();
        fnode = Factor();
        t1node = Term1();
        return CreateNode(OperatorDiv,t1node, fnode);
    }
    return CreateNodeNumber(1);
}

ASTNodeType *prefix::Factor()
{
    ASTNodeType* node;
    switch(m_crtToken.Type){
    case OpenParentesis:
        GetNextToken();
        node = Expression();
        Match(')');
        return node;
    case Minus:
        GetNextToken();
        node = Factor();
        return CreateUnaryNode(node);
    case Number:
    {
        double value = m_crtToken.Value;
        GetNextToken();
        return CreateNodeNumber(value);
    }
    default:{

        cout<<"Unexpected Token "<<m_crtToken.Symbol<<"at position "<<m_Index<<endl;

        }
    }
}

void prefix::Match(char expected)
{
    if(m_Text[m_Index-1] == expected){
        GetNextToken();
    }
    else{

        cout<<"Expected token "<< expected<< "at position "<< m_Index<< endl;
    }
}

ASTNodeType *prefix::CreateNode(NodeType type, ASTNodeType *left, ASTNodeType *right)
{
    ASTNodeType* node = new ASTNodeType;
    node->Type = type;
    node->Left = left;
    node->Right = right;
    return node;
}

ASTNodeType *prefix::CreateUnaryNode(ASTNodeType *left)
{
    ASTNodeType* node = new ASTNodeType;
    node->Type = UnaryMinus;
    node->Left = left;
    node->Right = nullptr;
    return node;
}

ASTNodeType *prefix::CreateNodeNumber(double value)
{
    ASTNodeType* node = new ASTNodeType;
    node->Type = NumberValue;
    node->Value = value;
    return node;
}
