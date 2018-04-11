#ifndef ASTNODE_H
#define ASTNODE_H

enum NodeType{
    Undefined,
    OperadorPlus,
    OperadorMinus,
    OperadorMul,
    OperadorDiv,
    UnaryMinus,
    NumberValue,
    OperatorRef,
    VariableValue,
    OperadorEq

};

class AstNode
{
public:
    NodeType Type;
    double Value;
    AstNode* Left;
    AstNode* Right;
    AstNode();
    ~AstNode(){
        delete Right;
        delete Left;
    }
};

#endif // ASTNODE_H
