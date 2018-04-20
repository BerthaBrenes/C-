#include <iostream>
#include "prefix.h"
#include "parseoascii.h"
#include "astnodetype.h"
#include "desicion.h"
#include "client.cpp"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    //Desicion("A = B /C;");
    //ASTNodeType* node =prefix("double Dee4 = 8;").ReturNode();
    char* hupa = "int G = 21;";
    ASTNodeType* node  = Desicion(hupa).ReturNode();
   // ASTNodeType* node =prefix(hupa).ReturNode();
     //("struct {");
    //Desicion(hupa);
    //ASTNodeType* node = prefix("} class Ta;").ReturNode();
    //cout<<parseoASCII("asfdg").charToint("352")<<endl;
    return 0;
}
