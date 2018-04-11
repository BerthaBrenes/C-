#include "prefix.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "parseoascii.h"
#include "factorydepends.h"

using namespace std;


prefix::prefix(const char *text)
{
    m_Text = text;
    m_Index = 0;
    cout<<"constructor"<<endl;
    GetNextToken();

    //Expression();

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
    case Declaration:
        cout<<"Operador Declaracion"<<endl;
        GetNextToken();
        tnode = Term();
        e1node = Expression1();
        return CreateNode(OperatorDecla, e1node,tnode);
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
        cout<<"Indice igual a 0, fin de la linea"<<endl;
        m_crtToken.Type = EndOfText;
        NodoLine->Print();
        return;
    }
    if(isdigit(m_Text[m_Index])){
        cout<<"encontro un numero"<<endl;
        m_crtToken.Type = Number;
        m_crtToken.Value = GetNumber();
        cout<<"Valor del numero"<<m_crtToken.Value<<endl;
        NodoLine->Right = CreateNodeNumber(m_crtToken.Value);
        NodoLine->Right->Type = VariableValue;
        GetNextToken();
        return;
    }
    if(islower(m_Text[m_Index])){
        cout<<"encontro un operador"<<endl;
        m_crtToken.Type = Reference;
        m_crtToken.Value = GetReference();
        cout<<"valor:"<<m_crtToken.Value<<endl;
        GetNextToken();
        return;
    }
    if(isupper(m_Text[m_Index])){
        cout<<"Encontro un variable"<<endl;
        m_crtToken.Type = Variable;
        m_crtToken.Value = GetVariable();
        cout<<"valor"<<m_crtToken.Value<<endl;
        NodoLine->Left = CreateNodeNumber(m_crtToken.Value);
        NodoLine->Left->Type = VariableName;
        GetNextToken();
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
        m_Index++;
        GetNextToken();
        break;
    case '*':
        m_crtToken.Type = Mul;
        cout<<"mul"<<endl;
        break;
    case '/':
        m_crtToken.Type = Div;
        break;
    case '(':
    {
        cout<<"Corchete"<<endl;
        m_crtToken.Type = OpenParentesis;
        NodoLine->Right = CreateNode(VariableValue);
        Match(')');
        GetNextToken();
        break;
    }
    case ')':
        m_crtToken.Type = ClosedParentesis;
        break;
    case '{':
        m_crtToken.Type = OpenCor;
        break;
    case '}':
        m_crtToken.Type = ClosedCor;
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
    cout<<"obtener variable"<<endl;
    SkipWhiteSpaces();
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
    cout<<"el nombre de la variables es: "<<buffer<<endl;
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
            ptrDepends->crear(floatingg);
            NodoLine->Type = OperatorRef;
            return 0;
        }else{
            break;
        }
    }
    case 'd':
    {
        cout<<"double"<<endl;
        if(Verificar(1, buffer)){
            ptrDepends->crear(doubless);
            NodoLine->Type = OperatorRef;
            NodoLine->Value = 1.0;
            return 1;
        }else{
            break;
        }
    }
    case 'i':{
        cout<<"int"<<endl;
        if(Verificar(2, buffer)){
            ptrDepends->crear(intigerr);
            NodoLine->Type = OperatorRef;
            NodoLine->Value = 2.0;
            return 2;
        }else{
            break;
        }
    }

    case 'l':{
        cout<<"long"<<endl;
        if(Verificar(3, buffer)){
            ptrDepends->crear(longerr);
            NodoLine->Type = OperatorRef;
            NodoLine->Value = 3.0;
            return 3;
        }else{
            break;
        }
    }

    case 'c':{
        cout<<"char"<<endl;
        if(Verificar(4, buffer)){
            ptrDepends->crear(charss);
            NodoLine->Type = OperatorRef;
            NodoLine->Value = 4.0;
            return 4;
        }else{
            break;
        }
    }
    case 's':{
        cout<<"struct"<<endl;
        if(Verificar(5,buffer)){
            ptrDepends->crear(structss);
            m_crtToken.Type = Declaration;
            NodoLine->Type = OperatorDecla;
            NodoLine->Value =5.0;
            return 5;
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
    case 5:{
        char str1[] = "struct";
        for(int i = 0; text[i]; i++){
            if(text[i] != str1[i]){
                cout<<"error de sintaxis"<<endl;
                return false;
            }
        }
        cout<<"Palabra Verificada"<<endl;
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
            indice++;
            m_Index++;
        }
        if(m_Text[m_Index]== '.'){
            cout<<"if de punto"<<endl;
            buffer[m_Index] = '*';
            m_Index++;
            while(isdigit(m_Text[m_Index])){
                buffer[indice] = m_Text[m_Index];
                indice++;
                m_Index++;
            }
        }
        if(m_Index - index == 0){
            cout<<"Number expected but not found"<<m_Index<<endl;
        }
       //memcpy(buffer,&m_Text[m_Index], m_Index-index);
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
        case OpenCor:
            GetNextToken();
            node = Expression();
            Match('}');
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
        m_Index++;
        char buffer[32] = {0};
        int indice = 0;
        while(m_Text[m_Index] != expected){
           buffer[indice] = m_Text[m_Index];
           cout<<"valor buffer: "<<buffer[m_Index]<<endl;
           m_Index++;
           indice++;
        }

        if(m_Text[m_Index] == 0){
            cout<<"Error sintactico, debe cerrar con las comillas"<<endl;
        }
        if(m_Text[m_Index] == expected){
            cout<<"Valor del buffer: "<<buffer<<endl;
            m_Index++;
            NodoLine->Right->value = buffer;
            cout<<"se cayo?"<<endl;
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

    ASTNodeType *prefix::CreateNode(NodeType type)
    {
        ASTNodeType* node = new ASTNodeType;
        node->Type = type;
        node->Left = nullptr;
        node->Right = nullptr;
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
        node->Value = value;
        return node;
    }

    ASTNodeType *prefix::CreateNodeChar(char *value)
    {
        ASTNodeType* node = new ASTNodeType;
        node->Type = VariableName;
//        node->Value = value;
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
