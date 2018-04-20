#ifndef FACTORYDEPENDS_H
#define FACTORYDEPENDS_H
#include <iostream>
#include "astnode.h"
#include "interfaces.h"
#include "map"


using namespace std;



class factorydepends
{
private:
    factorydepends();
    factorydepends(const factorydepends &){}
    factorydepends &operator = (const factorydepends &){
            return *this;
        }
    typedef map<int,interfaces::CreateInterfaceFn> FactoryMap;
    FactoryMap m_FactoryMap;
public:
    ~factorydepends(){
     m_FactoryMap.clear();
    }
    static factorydepends *Get(){
        static factorydepends instance;
        return &instance;
    }
    interfaces *CreateInterface(const astNode* interfaceType);
};


#endif // FACTORYDEPENDS_H
