#include "ir.h"
#include <iostream>


// Implement the evaluate() and print() methods for IntegerLiteral
int IntegerLiteral::evaluate() const {
    // Placeholder implementation
    // In a real scenario, this would return the integer value.
    return value;
}

void IntegerLiteral::print() const {
    // This will print the integer value to the console.
    std::cout << value;
}

// Implement the evaluate() and print() methods for VariableExpression
int VariableExpression::evaluate() const {
    // Placeholder implementation
    // In a real scenario, this might look up the variable's value in some sort of symbol table.
    return 0; // Returning 0 as a placeholder
}

void VariableExpression::print() const {
    // This will print the variable's name to the console.
    std::cout << name;
}

// Implement the evaluate() and print() methods for BinaryOperation
int BinaryOperation::evaluate() const {
    // Placeholder implementation
    // In a real scenario, this would perform the operation on the left and right operands.
    // Here's a simple example:
    int leftVal = left->evaluate();
    int rightVal = right->evaluate();

    switch (op) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return rightVal != 0 ? leftVal / rightVal : 0; // Guard against division by zero
        default: return 0; // Or throw an exception for an unsupported operator
    }
}

void BinaryOperation::print() const {
    // This will print the binary operation in a "(left op right)" format.
    std::cout << '(';
    left->print();
    std::cout << ' ' << op << ' ';
    right->print();
    std::cout << ')';
}

// Implement the print() method for Assignment
void Assignment::print() const {
    // This will print the assignment in a "variableName = expression;" format.
    std::cout << variableName << " = ";
    expression->print();
    std::cout << ";\n";
}

// Implement the print() method for Print
void Print::print() const {
    // This will print the expression in a "print expression;" format.
    std::cout << "print ";
    expression->print();
    std::cout << ";\n";
}

// Note: If the evaluate() method is also required for Assignment or Print, it would need to be declared and defined as well.
