#include "factorydepends.h"
#include "doubles.h"
#include "chars.h"
#include "floating.h"
#include "structs.h"
#include "intiger.h"
#include "longer.h"
#include "prueba.h"
#include "interfaces.h"
#include "astnodetype.h"

factorydepends::factorydepends()
{
    Register(0,&Floating::Create);
    Register(1, &doubles::Create);
    Register(2,&Intiger::Create);
    Register(3,&Longer::Create);
    Register(4,&Chars::Create);
    Register(5,&Structs::Create);
    Register(6,&Structs::Create);
}
void factorydepends::Register(const double interfaceType, interfaces::CreateInterfaceFn pfnCreate){
    m_FactoryMap[interfaceType] = pfnCreate;
}
interfaces *factorydepends::CreateInterface(const ASTNodeType* interface){
    FactoryMap::iterator it = m_FactoryMap.find(interface->Value);
    if(it != m_FactoryMap.end()){
       return it->second();
    }
    return NULL;
}


