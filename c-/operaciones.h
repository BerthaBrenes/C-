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
    astNode* CreateNodes(NodeType type, astNode* left, astNode* right);
    astNode* CreateNodes(NodeType type);
    astNode* CreateNodeNumber(double value);
    astNode* CreateNodeChar(char* value);
    astNode* NodoLine  = new astNode;
    int GetReference();
    bool Verificar(int tipo,char* text);
    int GetVariable();
    void GetMainToken();
    astNode* Validar(char* name);
    string to_strin(double x);
    ofstream es;
    ifstream ls;

public:
      Operaciones(char* text);
      astNode* ReturNode();
      Operaciones();
};

#endif // OPERACIONES_H
