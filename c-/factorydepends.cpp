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
#include "doubles.h"
#include "chars.h"
#include "floating.h"
#include "intiger.h"
#include "longer.h"
#include "structs.h"

factorydepends::factorydepends()
{

}

interfaces *factorydepends::CreateInterface(const ASTNodeType *interface){
    int x = 0;
    x = interface->Value;
    switch (x) {
    case 0:
        return Floating::Create();
        break;
    case 1:
        return doubles::Create();
        break;
    case 2:
        return Intiger::Create();
        break;
    case 3:
        return Longer::Create();
        break;
    case 4:
        return Chars::Create();
        break;
    case 5:
        return Structs::Create();
        break;
    case 6:
        return Structs::Create();
        break;
    default:
        cout<<"upsi default"<<endl;
        break;
    }
}


