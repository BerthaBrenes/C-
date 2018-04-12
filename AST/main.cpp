#include <iostream>
#include "prefix.h"
#include "parseoascii.h"
#include "astnodetype.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    ASTNodeType* node =prefix("char Dee4 = (uhy)").ReturNode();

    //prefix("struct{");
    //cout<<parseoASCII("asfdg").charToint("352")<<endl;
    return 0;
}
