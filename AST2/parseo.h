#ifndef PARSEO_H
#define PARSEO_H
#include "astnode.h"

enum TokenType{
    Error,
    Plus,
    Minus,
    Mul,
    Div,
    EndOfText,
    OpenParentesis,
    ClosedParentesis,
    Number,
    Reference,
    Variable,
    Equal
};

class parseo
{
    struct Token{
        TokenType Type;
        double Value;
        char Symbol;
    };
    Token m_crtToken;
    const char* m_Text;
    int m_Index;
private:
    AstNode* Expresion();
    AstNode* Expresion1();
    AstNode* Term();
    AstNode* Term1();
    AstNode* Factor();
    AstNode* CreateNode(NodeType type, AstNode* left, AstNode* right);
    AstNode* CreateUnaryNode(AstNode* left);
    AstNode* CreateNodeNumber(double value);
    void skipSpace();
    double GetValue();
    void Match(char expected);
    void GetNextToken();
    int GetReference();
    bool Verificar(int tipo,char* text);
    int GetVariable();
public:
    parseo(const char* text);
    parseo();

};

#endif // PARSEO_H
