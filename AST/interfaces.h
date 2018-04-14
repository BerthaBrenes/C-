#ifndef INTERFACES_H
#define INTERFACES_H
#include "astnodetype.h"
class interfaces{
   public:
    virtual void send(char* name,char* value) =0;
    virtual void send(char* name, double value) = 0;
    virtual void print()= 0;
    virtual void Free() = 0;
    virtual void Data(ASTNodeType* node) =0;
    typedef interfaces* (__stdcall *CreateInterfaceFn)(void);
};
#endif // INTERFACES_H
