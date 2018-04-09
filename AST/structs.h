#ifndef STRUCT_H
#define STRUCT_H
#include "factorydepends.h"

class structs: public factorydepends
{
public:
    structs();
    void send(char* name,int value);
};

#endif // STRUCT_H
