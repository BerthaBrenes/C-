#ifndef PREFIX_H
#define PREFIX_H
#include "astnodetype.h"
#include "factorydepends.h"
#include <iostream>
#include <fstream>

using namespace std;

enum TokenType{
    Error,
    Plus,
    Minus,
    Mul,
    Div,
    EndOfText,
    OpenParentesis,
    OpenCor,
    OpenCom,
    ClosedCom,
    ClosedParentesis,
    ClosedCor,
    Number,
    Reference,
    Variable,
    Equal,
    Declaration

};

class prefix
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
    void Match(char expected);
    ASTNodeType* CreateNode(NodeType type, ASTNodeType* left, ASTNodeType* right);
    ASTNodeType* CreateNode(NodeType type);
    ASTNodeType* CreateNodeNumber(double value);
    ASTNodeType* CreateNodeChar(char* value);
    ASTNodeType* NodoLine  = new ASTNodeType;
    int GetReference();
    bool Verificar(int tipo,char* text);
    int GetVariable();
    string to_strin(double x);
    //factorydepends *ptrDepends = NULL;

public:
      prefix(const char* text);
      ASTNodeType* ReturNode();
      prefix();
};

#endif // PREFIX_H
