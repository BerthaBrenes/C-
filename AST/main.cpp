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
    Desicion("A = B /C;");
    //ASTNodeType* node =prefix("double Dee4 = 8;").ReturNode();
   //ASTNodeType* node =prefix("char Alv = (putisima);").ReturNode();
     //("struct {");
    //ASTNodeType* node = prefix("} class Ta;").ReturNode();
    //cout<<parseoASCII("asfdg").charToint("352")<<endl;
    return 0;
}
