#ifndef LONGER_H
#define LONGER_H
#include "factorydepends.h"

class longer: public factorydepends
{
public:
    longer();
    void send(char* name,int value);
};

#endif // LONGER_H
