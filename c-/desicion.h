#ifndef DESICION_H
#define DESICION_H
#include "astnode.h"
#include <fstream>
#include <iostream>
#include <fstream>
#include "prefix.h"
using namespace std;



class Desicion
{
    struct Token{
        TokenType Type;
        double  Value;
        char Symbol;
    };
    Token m_crtToken;
    char* m_Text;
    int m_Index;

private:

    void SkipWhiteSpaces();
    void GetNextToken();
    double GetNumber();
    void FindNextWay(int puerto);
    void Match(char expected);
    astNode* CreateNode(NodeType type, astNode* left, astNode* right);
    astNode* CreateNode(NodeType type);
    astNode* CreateNodeNumber(double value);
    astNode* CreateNodeChar(char* value);
    astNode* NodoLine  = new astNode;
    int GetReference();
    bool Verificar(int tipo,char* text);
    int GetVariable();


public:
      Desicion(char* text, int puerto);
      astNode* ReturNode();
      Desicion();
};

#endif // DESICION_H
