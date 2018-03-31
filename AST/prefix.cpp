#include "prefix.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "parseoascii.h"

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
    cout<<"se supone que debia entrar aqui"<<endl;
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
    cout<<"Expresion 1"<<endl;
    switch (m_crtToken.Type) {
    case Plus:
        cout<<"Operador suma "<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expression1();
        return CreateNode(OperatorPlus, e1node, tnode);
    case Reference:
        cout<<"Operador ref "<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expression1();
        return CreateNode(OperatorRef,e1node,tnode);
    case Minus:
        cout<<"Operador Minus"<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expression1();
        return CreateNode(OperatorMinus, e1node, tnode);
    case Variable:
        cout<<"Operador Variable"<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expression1();
        return CreateNode(VariableValue, e1node,tnode);
    case Equal:
        cout<<"Operator Equal"<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expression1();
        return CreateNode(OperadorEq, e1node,tnode);
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
        cout<<"encontro un numero"<<endl;
        m_crtToken.Type = Number;
        m_crtToken.Value = GetNumber();
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
    switch (m_Text[m_Index]) {
    case '+':
        m_crtToken.Type = Plus;
        cout<<"plus"<<endl;
        break;
    case '-':
        m_crtToken.Type = Minus;
        cout<<"minus"<<endl;
        break;
    case '=':
        m_crtToken.Type = Equal;
        cout<< "referencia a copia"<<endl;
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
int prefix::GetVariable(){
    cout<<"obtener varibale"<<endl;
    SkipWhiteSpaces();
    cout<<"obtener letra"<<endl;
    int index = m_Index;
    char buffer[32] = {0};
    int indice = 0;
    while(isupper(m_Text[m_Index])){
        buffer[indice] = m_Text[m_Index];
        indice++;
        m_Index++;

    }
    if(m_Index - index == 0){
        cout<<"letter expected but not found"<<m_Index<<endl;
    }
    cout<<"el mismo puto problema: "<<buffer<<endl;
    return parseoASCII(buffer).convert();
}

int prefix::GetReference()
{
    SkipWhiteSpaces();
    cout<<"obtener letra"<<endl;
    int index = m_Index;
    char buffer[6]={0};
    int indice = 0;
    while(islower(m_Text[m_Index])){
        buffer[indice] = m_Text[m_Index];
        indice++;
        m_Index++;
    }
    cout<<"valor de buffer: "<<buffer[0]<<endl;

    switch(buffer[0]){
    case 'f':{
        cout<<"float"<<endl;
        if(Verificar(0, buffer)){
            return 0;
        }else{
            break;
        }
    }
    case 'd':
    {
        cout<<"double"<<endl;
        if(Verificar(1, buffer)){
            return 1;
        }else{
            break;
        }
    }
    case 'i':{
        cout<<"int"<<endl;
        if(Verificar(2, buffer)){
            return 2;
        }else{
            break;
        }
    }

    case 'l':{
        cout<<"long"<<endl;
        if(Verificar(3, buffer)){
            return 3;
        }else{
            break;
        }
    }

    case 'c':{
        cout<<"char"<<endl;
        if(Verificar(4, buffer)){
            return 4;
        }else{
            break;
        }
    }

    }

    if(m_Index - index == 0){
        cout<<"letter expected but not found"<<m_Index<<endl;
    }
}
bool prefix::Verificar(int tipo, char* text){
    cout<<"verifcar"<<endl;
    switch(tipo){
    case 0:{
        char str1[] = "float";
        for(int i = 0;text[i];i++){
            if(text[i] != str1[i]){
                cout<<"error de sintaxis"<<endl;
                return false;
            }
        }
        cout<<"palabra verifcada"<<endl;
        return true;
    }
    case 1:{
        char str1[] = "double";
        for(int i = 0;text[i];i++){
            if(text[i] != str1[i]){
                cout<<"error de sintaxis"<<endl;
                return false;
            }
        }
        cout<<"palabra verifcada"<<endl;
        return true;
    }
    case 2:{
        char str1[4] = "int";
        for(int i = 0;text[i];i++){
            if(text[i] != str1[i]){
                cout<<"error de sintaxis"<<endl;
                return false;
            }
        }
        cout<<"palabra verifcada"<<endl;
        return true;
    }
    case 3:{
        char str1[] = "long";
        for(int i = 0;text[i];i++){
            if(text[i] != str1[i]){
                cout<<"error de sintaxis"<<endl;
                return false;
            }
        }
        cout<<"palabra verifcada"<<endl;
        return true;
    }
    case 4:{
        char str1[] = "char";
        for(int i = 0;text[i];i++){
            if(text[i] != str1[i]){
                cout<<"error de sintaxis"<<endl;
                return false;
            }
        }
        cout<<"palabra verifcada"<<endl;
        return true;
    }
    }
}
    double prefix::GetNumber()
    {
        SkipWhiteSpaces();
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
        double result = parseoASCII().charToint(buffer);
        cout<<"valor buffer"<<result<<endl;
        return result;
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
    /**
 * Para la deteccion de operadores, solo voy a tomar la
 * primera letra de la referencia porque no logro detentar el operando completo
 * float => f =>0
 * double => d =>1
 * int => i =>2;
 * long => l =>3
 * char => c =>4
 * struct => s =>5
 **/
