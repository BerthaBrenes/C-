#ifndef STRINGS_H
#define STRINGS_H
#include "factorydepends.h"


class Chars :public factorydepends
{
public:
    Chars();
    void send(char* name,int value);
};

#endif // STRINGS_H
