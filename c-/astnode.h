#ifndef ASTNODE_H
#define ASTNODE_H
<<<<<<< HEAD

=======
#include "json.hpp"
#include "fstream"

using json = nlohmann::json;
>>>>>>> 4223c5c875a09a5eb82ed7eed487c6c148e6e600
enum NodeType{
    Undefined,
    OperatorPlus,
    OperatorMinus,
    OperatorMul,
    OperatorDiv,
    UnaryMinus,
    NumberValue,
    OperatorRef,
    VariableValue,
    VariableName,
    OperadorEq,
    OperatorDecla,

};
class astNode
{
public:
    NodeType Type;
    double Value;
    char* value;
<<<<<<< HEAD
=======
    json data;
    int puerto;
>>>>>>> 4223c5c875a09a5eb82ed7eed487c6c148e6e600
    astNode* Left;
    astNode* Right;
    astNode();
    void Print();
    ~astNode(){
        delete Right;
        delete Left;
    }
};

#endif // ASTNODE_H
