#ifndef ASTNODE_H
#define ASTNODE_H
#include "json.hpp"
#include "fstream"

using json = nlohmann::json;
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
    json data;
    int puerto;
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
