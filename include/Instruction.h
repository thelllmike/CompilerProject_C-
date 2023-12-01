#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include <memory>

class InstructionNode {
public:
    // Constructor declaration
    InstructionNode(std::vector<std::unique_ptr<InstructionNode>> children);

    // Other member functions and variables
    // ...

private:
    std::vector<std::unique_ptr<InstructionNode>> children;
};

#endif // INSTRUCTION_H
