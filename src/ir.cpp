#include "ir.h"

int IntegerLiteral::evaluate() const {
    return value;
}

void IntegerLiteral::print() const {
    std::cout << value;
}

int VariableExpression::evaluate() const {
    // Placeholder: Variable evaluation depends on your context (symbol table, etc.)
    return 0;
}

void VariableExpression::print() const {
    std::cout << name;
}

int BinaryOperation::evaluate() const {
    int leftVal = left->evaluate();
    int rightVal = right->evaluate();
    switch (op) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return rightVal != 0 ? leftVal / rightVal : 0; // Guard against division by zero
        default: throw std::runtime_error("Unsupported operator");
    }
}

void BinaryOperation::print() const {
    left->print();
    std::cout << " " << op << " ";
    right->print();
}

void Assignment::execute() {
    // Execute the assignment. This is a placeholder.
    // In a real scenario, this would involve updating a symbol table or memory.
    std::cout << variableName << " = ";
    expression->print();
    std::cout << "\n";
}

void Print::execute() {
    // Execute the print instruction. This is a placeholder.
    expression->print();
    std::cout << "\n";
}
