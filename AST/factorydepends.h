#ifndef FACTORYDEPENDS_H
#define FACTORYDEPENDS_H
#include <iostream>
#include "astnodetype.h"
using namespace std;



class factorydepends
{
public:
    factorydepends();
    virtual void send(char* name, int value) = 0;
    static factorydepends* crear(ASTNodeType* nodo);
};

#endif // FACTORYDEPENDS_H
