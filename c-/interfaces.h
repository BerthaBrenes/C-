#ifndef INTERFACES_H
#define INTERFACES_H
//#define "__stdcall"
#include "astnodetype.h"
class interfaces{
   public:
    virtual void send(char* name,char* value) =0;
    virtual void send(char* name, double value) = 0;
    virtual void print()= 0;
    virtual void Free() = 0;
    virtual ASTNodeType* Data(ASTNodeType* node) =0;
    virtual void saveStruct(ASTNodeType* node) =0;
    typedef interfaces*  CreateInterfaceFn;
};
#endif // INTERFACES_H
