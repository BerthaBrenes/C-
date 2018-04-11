#ifndef ASTNODETYPE_H
#define ASTNODETYPE_H

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
