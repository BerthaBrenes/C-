#include "operaciones.h"
#include <iostream>

using namespace std;
Operaciones::Operaciones(const char *text, int port)
{
    cout<<"encontre una variable"<<endl;
    m_Text = text;
    m_Index = 0;
    GetVariable();
}

Operaciones::Operaciones()
{

}
void Operaciones::SkipWhiteSpaces()
{
    while(isspace(m_Text[m_Index])){
        cout<<"whitespace, index "<<endl;
        m_Index++;
    }
}

void Operaciones::GetNextToken()
{
    SkipWhiteSpaces();
    cout<<"Encontrar el token secundario"<<endl;
    switch (m_Text[m_Index]) {
    case '+':
        cout<<"suma"<<endl;
        m_Index++;
        GetVariable();
        break;
    case '/':
        cout<<"division"<<endl;
        m_Index++;
        GetVariable();
        break;
    case '*':
        cout<<"multiplicacion"<<endl;
        m_Index++;
        GetVariable();
        break;
    case '-':
        cout<<"resta"<<endl;
        m_Index++;
        GetVariable();
        break;
    case ';':
        cout<<"final de la linea"<<endl;
        break;
    default:
        cout<<"no encontre mas"<<endl;
        break;
    }
}

    ASTNodeType *Operaciones::CreateNodes(NodeType type, ASTNodeType *left, ASTNodeType *right)
    {
        ASTNodeType* node = new ASTNodeType;
        node->Type = type;
        node->Left = left;
        node->Right = right;
        return node;
    }

    ASTNodeType *Operaciones::CreateNodes(NodeType type)
    {
        ASTNodeType* node = new ASTNodeType;
        node->Type = type;
        node->Left = nullptr;
        node->Right = nullptr;
        return node;
    }
    int Operaciones::GetVariable(){
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

        GetMainToken();
        return 1;
    }
    void Operaciones::GetMainToken(){
        SkipWhiteSpaces();
        cout<<"Encontrar el token principal"<<endl;
        switch (m_Text[m_Index]) {
        case '=':
            cout<<"referencia a copia"<<endl;
            m_Index++;
            GetVariable();
            break;
        case '/':
            cout<<"division"<<endl;
            m_Index++;
            GetVariable();
            break;
        case '*':
            cout<<"multiplicacion"<<endl;
            m_Index++;
            GetVariable();
        default:
            cout<<"no mas token principal"<<endl;
            GetNextToken();
            break;
        }

    }

    ASTNodeType *Operaciones::Validar(char *name)
    {
        SkipWhiteSpaces();
        //Get("name");


    }
