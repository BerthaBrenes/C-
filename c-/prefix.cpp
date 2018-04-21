#include "prefix.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "parseoascii.h"
#include "factorydepends.h"
#include "fstream"
#include <string>
#include <cstring>
#include <sstream>
#include <interfaces.h>

using namespace std;


prefix::prefix(char *text, int puerto)
{
    m_Text = text;
    m_Index = 0;
    m_puerto = puerto;
    cout<<"constructor"<<endl;
    GetNextToken();

}

prefix::prefix()
{

}

void prefix::SkipWhiteSpaces()
{
    while(isspace(m_Text[m_Index])){
        cout<<"whitespace, index "<<endl;
        m_Index++;
    }
}

void prefix::GetNextToken()
{
    SkipWhiteSpaces();
    m_crtToken.Value = 0;
    m_crtToken.Symbol = 0;
    cout<< "Get next token"<<endl;
    if(m_Text[m_Index]==0){
        cout<<"Indice igual a 0, fin de la linea en struct"<<endl;
        m_crtToken.Type = EndOfText;
        string cadena;
        ls.open("boolean.txt",ios::in);
        if(!ls.fail()){
            while(!ls.eof()){
                getline(ls,cadena);
                cout<<cadena<<endl;
                if(cadena == "true"){
                    cout<<"referencias nuevas"<<endl;
                    return;
                }
            }
            ls.close();
            ofstream escrituraArc;
            escrituraArc.open("Struc.txt",ios::ate);
            escrituraArc<<"valor del nodo"<<endl;
            escrituraArc<<to_strin(NodoLine->Value)<<endl;
            escrituraArc.close();
        }else{
            cout<<"error al abrir archivos"<<endl;
        }
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
        GetNextToken();
        return;
    }
    m_crtToken.Type = Error;
    switch (m_Text[m_Index]) {
    case ';':{
        m_crtToken.Type = EndOfText;
        cout<<"final de una linea normal de codigo"<<endl;
        string cadena;
        ls.open("boolean.txt",ios::in);
        if(!ls.fail()){
            while(!ls.eof()){
                getline(ls,cadena);
                cout<<cadena<<endl;
                if(cadena == "true"){
                    cout<<"interfaces para struct"<<endl;
                    interfaces *ptrDepends = factorydepends::Get()->CreateInterface(NodoLine);
                    cout<<"prueba"<<endl;
                    ptrDepends->saveStruct(NodoLine);
                    return;
                }
                else{
                    cout<<"struc cerrado"<<endl;
                   // NodoLine->Print();
                    cout<<"aqui creo que no llego"<<endl;
                    NodoLine->puerto = m_puerto;
                    interfaces *ptrDep = factorydepends::Get()->CreateInterface(NodoLine);
                    cout<<"no se que hagp aqio"<<endl;
                    ptrDep->Data(NodoLine);
                    cout<<"no se que hagp aqio"<<endl;
                    return;
                }
            }
            ls.close();
        }else{
            cout<<"creo que se metio aqui porque el archivo no existe"<<endl;
        }
    }
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
    {
        m_crtToken.Type = OpenCor;
        cout<<"corchete, abriendo struct"<<endl;
        es.open("boolean.txt",ios::out);
        es<<"true"<<endl;
        es.close();
        m_Index++;
        GetNextToken();
        break;
    }
    case '}':
        cout<<"corchete, cerrando struct"<<endl;
        es.open("boolean.txt",ios::out);
        es<<"false"<<endl;
        es.close();
        remove("prueba.json");
        m_crtToken.Type = ClosedCor;
        m_Index++;
        GetNextToken();
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
    while(isalnum(m_Text[m_Index])){
        buffer[indice] = m_Text[m_Index];
        indice++;
        m_Index++;

    }
    if(m_Index - index == 0){
        cout<<"letter expected but not found"<<m_Index<<endl;
    }
    cout<<"el nombre de la variables es: "<<buffer<<endl;
    NodoLine->Left = CreateNodeNumber(0);
    NodoLine->Left->Type = VariableName;
    NodoLine->Left->value = buffer;
    return parseoASCII(buffer).convert();
}

string prefix::to_strin(double x)
{
    ostringstream ss;
    ss<<x;
    return ss.str();
}

ASTNodeType *prefix::ReturNode()
{
    return NodoLine;
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
            NodoLine->Type = OperatorRef;
            NodoLine->Value = 0.0;
            return 0;
        }else{
            break;
        }
    }
    case 'd':
    {
        cout<<"double"<<endl;
        if(Verificar(1, buffer)){
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
            NodoLine->Type = OperatorRef;
            NodoLine->Value = 3.0;
            return 3;
        }else{
            break;
        }
    }

    case 'c':{
        cout<<"char"<<endl;
        if(buffer[1] == 'h')
        {
            if(Verificar(4, buffer)){
                NodoLine->Type = OperatorRef;
                NodoLine->Value = 4.0;
                return 4;
            }else{
                break;
            }
        }if(buffer[1]== 'l'){
            cout<<"class"<<endl;
            if(Verificar(6,buffer)){
                //m_crtToken.Type = OperatorRef;
                NodoLine->Type = OperatorRef;
                NodoLine->Value = 6.0;
                NodoLine->Right= CreateNodeNumber(0);
                NodoLine->Type = OperatorRef;
                NodoLine->Right->Value = 0.0;
                return 6;
            }else{
                break;
            }
        }
    }

    case 's':{
        cout<<"struct"<<endl;
        if(Verificar(5,buffer)){
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
    case 6:
        char str1[] = "class";
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
void prefix::Match(char expected)
{
    m_Index++;
    char varas[9] = {0};
    int indice = 0;
    while(m_Text[m_Index] != expected){
        varas[indice] = m_Text[m_Index];
        cout<<"valor buffer: "<<varas[indice]<<endl;
        m_Index++;
        indice++;
    }

    if(m_Text[m_Index] == 0){
        cout<<"Error sintactico, debe cerrar con las comillas"<<endl;
    }
    if(m_Text[m_Index] == expected){
        cout<<"Valor del buffer: "<<varas<<endl;
        NodoLine->Right->value = varas;
        m_Index++;
        return;

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
