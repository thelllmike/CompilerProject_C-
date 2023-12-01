#include "Instruction.h"

// Constructor implementation
InstructionNode::InstructionNode(std::vector<std::unique_ptr<InstructionNode>> children)
    : children(std::move(children)) // Initialize the member variable
{
    // Constructor logic here
}
