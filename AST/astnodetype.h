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
    OperadorEq
};

class ASTNodeType
{
public:
    NodeType Type;
    double Value;
    ASTNodeType* Left;
    ASTNodeType* Right;
    ASTNodeType();
    ~ASTNodeType(){
        delete Right;
        delete Left;
    }
};

#endif // ASTNODETYPE_H
