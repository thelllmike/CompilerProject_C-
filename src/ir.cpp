#include "include/ir.h"

// Destructor implementations for base classes with virtual destructors
Expression::~Expression() = default;
Instruction::~Instruction() = default;

// You might have additional methods or logic that belongs to the IR nodes.
// For example, if you had a visitor pattern setup for your IR nodes,
// you would implement the accept method for each node here.

// For example, an evaluation method for IntegerLiteral could look like this:
int IntegerLiteral::evaluate() const {
    return value;
}

// Similarly, you could implement an evaluate method for BinaryOperation like this:
int BinaryOperation::evaluate() const {
    int leftVal = left->evaluate();
    int rightVal = right->evaluate();
    switch (op) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return rightVal != 0 ? leftVal / rightVal : 0; // Simple error handling
        default: return 0; // Should add error handling for unsupported operations
    }
}

// If you had a method to print out the IR nodes in a human-readable format, it might look like this:
void IntegerLiteral::print() const {
    std::cout << value;
}

void VariableExpression::print() const {
    std::cout << name;
}

void BinaryOperation::print() const {
    std::cout << '(';
    left->print();
    std::cout << ' ' << op << ' ';
    right->print();
    std::cout << ')';
}

void Assignment::print() const {
    std::cout << variableName << " = ";
    expression->print();
    std::cout << ";\n";
}

void Print::print() const {
    std::cout << "print ";
    expression->print();
    std::cout << ";\n";
}
