#ifndef IR_H
#define IR_H

#include <string>
#include <vector>
#include <memory>

// Abstract class for any expression in the IR
class Expression {
public:
    virtual ~Expression() = default;
    // You could add evaluation methods or visitor patterns here
};

// Expression for integer literals
class IntegerLiteral : public Expression {
public:
    int value;

    explicit IntegerLiteral(int value) : value(value) {}
};

// Expression for variables
class VariableExpression : public Expression {
public:
    std::string name;

    explicit VariableExpression(std::string name) : name(std::move(name)) {}
};

// Binary operation expression
class BinaryOperation : public Expression {
public:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
    char op; // Operator: '+', '-', '*', '/'

    BinaryOperation(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right, char op)
        : left(std::move(left)), right(std::move(right)), op(op) {}
};

// Base class for any IR instruction
class Instruction {
public:
    virtual ~Instruction() = default;
    // Other methods for execution or visiting could be added here
};

// Assignment instruction
class Assignment : public Instruction {
public:
    std::string variableName;
    std::unique_ptr<Expression> expression;

    Assignment(std::string variableName, std::unique_ptr<Expression> expression)
        : variableName(std::move(variableName)), expression(std::move(expression)) {}
};

// Print instruction
class Print : public Instruction {
public:
    std::unique_ptr<Expression> expression;

    explicit Print(std::unique_ptr<Expression> expression)
        : expression(std::move(expression)) {}
};

// The entire IR for a program
class IRProgram {
public:
    std::vector<std::unique_ptr<Instruction>> instructions;

    // Add an instruction to the program
    void addInstruction(std::unique_ptr<Instruction> instruction) {
        instructions.push_back(std::move(instruction));
    }
};

#endif // IR_H
