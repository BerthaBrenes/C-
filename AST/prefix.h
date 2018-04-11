#ifndef PREFIX_H
#define PREFIX_H
#include "astnodetype.h"
#include "factorydepends.h"

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
    ASTNodeType* Expression();
    void SkipWhiteSpaces();
    ASTNodeType *Expression1();
    void GetNextToken();
    double GetNumber();
    ASTNodeType* Term();
    ASTNodeType* Term1();
    ASTNodeType* Factor();
    void Match(char expected);
    ASTNodeType* CreateNode(NodeType type, ASTNodeType* left, ASTNodeType* right);
    ASTNodeType* CreateNode(NodeType type);
    ASTNodeType* CreateUnaryNode(ASTNodeType* left);
    ASTNodeType* CreateNodeNumber(double value);
    ASTNodeType* CreateNodeChar(char* value);
    ASTNodeType* NodoLine  = new ASTNodeType;
    int GetReference();
    bool Verificar(int tipo,char* text);
    int GetVariable();
    factorydepends *ptrDepends;
public:
      prefix(const char* text);
      prefix();
};

#endif // PREFIX_H
