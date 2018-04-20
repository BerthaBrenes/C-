#include <iostream>
#include "prefix.h"
#include "parseoascii.h"
#include "astnodetype.h"
#include "desicion.h"
//#include "client.cpp"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Desicion("A = B /C;");
    //ASTNodeType* node =prefix("double Dee4 = 8;").ReturNode();
<<<<<<< HEAD
    char* hupa = "int G = 21;";
    //ASTNodeType* node  = Desicion(hupa).ReturNode();
   // ASTNodeType* node =prefix(hupa).ReturNode();
=======

    json J;
    J["type"] = "char";
    J["value"] = "strings";
    J["label"] = "Numerod";
    J["size"] = 1;
    J["countr"] = 1;
    Execute(J.dump());
   // Execute(prueba.called());
    //ASTNodeType* node =prefix("int G = 21;").ReturNode();
>>>>>>> 4223c5c875a09a5eb82ed7eed487c6c148e6e600
     //("struct {");
    //Desicion(hupa);
    //ASTNodeType* node = prefix("} class Ta;").ReturNode();
    //cout<<parseoASCII("asfdg").charToint("352")<<endl;
    return 0;
}
