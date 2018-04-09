#ifndef FACTORYDEPENDS_H
#define FACTORYDEPENDS_H
#include <iostream>

using namespace std;

enum tipo{
    structss,
    intigerr,
    charss,
    floatingg,
    doubless,
    longerr,
};

class factorydepends
{
public:
    factorydepends();
    static factorydepends* crear(tipo tip);
};

#endif // FACTORYDEPENDS_H
