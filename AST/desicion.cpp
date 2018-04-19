#include "desicion.h"
#include "prefix.h"
#include "operaciones.h"

Desicion::Desicion(const char *text)
{
    m_Text = text;
    m_Index = 0;
    if(isdigit(m_Text[m_Index])){
        cout<<"encontro un numero"<<endl;
        return;
    }
    if(islower(m_Text[m_Index])){
        cout<<"encontro un operador"<<endl;
        FindNextWay();
        return;
    }
    if(isupper(m_Text[m_Index])){
        new Operaciones(m_Text);
        cout<<"Encontro un variable"<<endl;

        return;
    }


}

Desicion::Desicion()
{

}
void Desicion::SkipWhiteSpaces()
{
    while(isspace(m_Text[m_Index])){
        cout<<"whitespace, index "<<endl;
        m_Index++;
    }
}

void Desicion::FindNextWay()
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
            cout<<"se verifico"<<endl;
            ASTNodeType* node =prefix(m_Text).ReturNode();
            break;
        }else{
            break;
        }
    }
    case 'd':
    {
        cout<<"double"<<endl;
        if(Verificar(1, buffer)){
            cout<<"se verifico"<<endl;
            ASTNodeType* node =prefix(m_Text).ReturNode();
            break;
        }else{
            break;
        }
    }
    case 'i':{
        cout<<"int"<<endl;
        if(Verificar(2, buffer)){
            cout<<"se verifico"<<endl;
            ASTNodeType* node =prefix(m_Text).ReturNode();
            break;
        }else{
            break;
        }
    }

    case 'l':{
        cout<<"long"<<endl;
        if(Verificar(3, buffer)){
            cout<<"se verifico"<<endl;
            ASTNodeType* node =prefix(m_Text).ReturNode();
            break;
        }else{
            break;
        }
    }

    case 'c':{
        cout<<"char"<<endl;
        if(buffer[1] == 'h')
        {
            if(Verificar(4, buffer)){
                cout<<"se verifico"<<endl;
                ASTNodeType* node =prefix(m_Text).ReturNode();
                break;
            }else{
                break;
            }
        }if(buffer[1]== 'l'){
            cout<<"class"<<endl;
            if(Verificar(6,buffer)){
                cout<<"se verifico"<<endl;
                ASTNodeType* node =prefix(m_Text).ReturNode();
                break;
            }else{
                break;
            }
        }
    }

    case 's':{
        cout<<"struct"<<endl;
        if(Verificar(5,buffer)){
            cout<<"se verifico"<<endl;
            ASTNodeType* node =prefix(m_Text).ReturNode();
            break;
        }else{
            break;
        }
    }

    }

    if(m_Index - index == 0){
        cout<<"letter expected but not found"<<m_Index<<endl;
    }

}

bool Desicion::Verificar(int tipo, char *text)
{

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
