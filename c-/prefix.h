#ifndef PREFIX_H
#define PREFIX_H
#include "astnode.h"
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
    char* m_Text;
    int m_Index;
    int m_puerto;
private:

    void SkipWhiteSpaces();
    void GetNextToken();
    double GetNumber();
    void Match(char expected);
    astNode* CreateNode(NodeType type, astNode* left, astNode* right);
    astNode* CreateNode(NodeType type);
    astNode* CreateNodeNumber(double value);
    astNode* CreateNodeChar(char* value);
    astNode* NodoLine  = new astNode;
    int GetReference();
    bool Verificar(int tipo,char* text);
    int GetVariable();
    string to_strin(double x);
    //factorydepends *ptrDepends = NULL;

    ofstream es;
    ifstream ls;

public:

      prefix(char* text, int puerto);
      astNode* ReturNode();
      prefix();
};

#endif // PREFIX_H
