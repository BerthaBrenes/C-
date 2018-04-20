#ifndef ASTNODETYPE_H
#define ASTNODETYPE_H
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
class ASTNodeType
{
public:
    NodeType Type;
    double Value;
    char* value;
    json data;
    int puerto;
    ASTNodeType* Left;
    ASTNodeType* Right;
    ASTNodeType();
    void Print();
    void Print(ASTNodeType* root);
    ~ASTNodeType(){
        delete Right;
        delete Left;
    }
};

#endif // ASTNODETYPE_H
