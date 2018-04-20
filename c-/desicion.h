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
<<<<<<< HEAD
    void FindNextWay();
=======
    void FindNextWay(int puerto);
>>>>>>> 4223c5c875a09a5eb82ed7eed487c6c148e6e600
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
<<<<<<< HEAD
      Desicion(char* text);
=======
      Desicion(char* text, int puerto);
>>>>>>> 4223c5c875a09a5eb82ed7eed487c6c148e6e600
      astNode* ReturNode();
      Desicion();
};

#endif // DESICION_H
