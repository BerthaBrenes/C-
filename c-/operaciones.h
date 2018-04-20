#ifndef OPERACIONES_H
#define OPERACIONES_H
#include "prefix.h"

class Operaciones
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
    void Match(char expected);
    ASTNodeType* CreateNodes(NodeType type, ASTNodeType* left, ASTNodeType* right);
    ASTNodeType* CreateNodes(NodeType type);
    ASTNodeType* CreateNodeNumber(double value);
    ASTNodeType* CreateNodeChar(char* value);
    ASTNodeType* NodoLine  = new ASTNodeType;
    int GetReference();
    bool Verificar(int tipo,char* text);
    int GetVariable();
    void GetMainToken();
    ASTNodeType* Validar(char* name);
    string to_strin(double x);
    ofstream es;
    ifstream ls;

public:
      Operaciones(char* text);
      ASTNodeType* ReturNode();
      Operaciones();
};

#endif // OPERACIONES_H
