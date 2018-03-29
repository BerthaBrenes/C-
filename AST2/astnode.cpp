#include "astnode.h"

AstNode::AstNode()
{
    Type = Undefined;
    Value = 0;
    Left = nullptr;
    Right = nullptr;
}
