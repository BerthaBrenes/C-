#ifndef FLOATING_H
#define FLOATING_H
#include "factorydepends.h"

class floating: public factorydepends
{
public:
    floating();
    void send(char* name,int value);
};

#endif // FLOATING_H
