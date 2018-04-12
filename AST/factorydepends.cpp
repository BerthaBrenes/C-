#include "factorydepends.h"
#include "intiger.h"
#include "doubles.h"
#include "chars.h"
#include "longer.h"
#include "structs.h"
#include "floating.h"
#include "prueba.h"


factorydepends::factorydepends()
{

}

factorydepends *factorydepends::crear(ASTNodeType* node)
{
    double p = node->Value;
    int y = int(p);
    switch (y) {
    case 0:
        cout<<"float"<<endl;
        break;
        floating();
    case 1:
        cout<<"double"<<endl;
        break;
    case 2:
        cout<<"int"<<endl;
        break;
    case 3:
        cout<<"long"<<endl;
        break;
    case 4:
        cout<<"Char"<<endl;
        break;
    case 5:
        cout<<"struct"<<endl;
        break;
    }
}
