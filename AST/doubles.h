#ifndef DOUBLES_H
#define DOUBLES_H
#include "factorydepends.h"

class doubles: public factorydepends
{
public:
    doubles();
    void send(char* name,int value);
};

#endif // DOUBLES_H
