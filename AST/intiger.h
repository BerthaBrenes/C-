#ifndef INTIGER_H
#define INTIGER_H
#include "factorydepends.h"

class intiger: public factorydepends
{
public:
    intiger();
    void send(char* name,int value);
};

#endif // INTIGER_H
