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

factorydepends *factorydepends::crear(tipo tip)
{
    if(tip == structss){
        return new structs();
    }
    if(tip == intigerr){
        return new intiger();
    }
    if(tip == charss){
        return new Chars();
    }
    if(tip == floatingg){
        return new floating();
    }
    if(tip == doubless){
        return new doubles();
    }
    if(tip == longerr){
        return new longer();
    }
}
