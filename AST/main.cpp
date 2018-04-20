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

    json J;
    J["type"] = "char";
    J["value"] = "strings";
    J["label"] = "Numerod";
    J["size"] = 1;
    J["countr"] = 1;
    Execute(J.dump());
   // Execute(prueba.called());
    //ASTNodeType* node =prefix("int G = 21;").ReturNode();
     //("struct {");
    //ASTNodeType* node = prefix("} class Ta;").ReturNode();
    //cout<<parseoASCII("asfdg").charToint("352")<<endl;
    return 0;
}
