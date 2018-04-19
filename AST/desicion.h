#ifndef DESICION_H
#define DESICION_H
#include <astnodetype.h>
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
    const char* m_Text;
    int m_Index;

private:

    void SkipWhiteSpaces();
    void GetNextToken();
    double GetNumber();
    void FindNextWay();
    void Match(char expected);
    ASTNodeType* CreateNode(NodeType type, ASTNodeType* left, ASTNodeType* right);
    ASTNodeType* CreateNode(NodeType type);
    ASTNodeType* CreateNodeNumber(double value);
    ASTNodeType* CreateNodeChar(char* value);
    ASTNodeType* NodoLine  = new ASTNodeType;
    int GetReference();
    bool Verificar(int tipo,char* text);
    int GetVariable();


public:
      Desicion(const char* text);
      ASTNodeType* ReturNode();
      Desicion();
};

#endif // DESICION_H
