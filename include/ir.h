#ifndef IR_H
#define IR_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Expression {
public:
    virtual ~Expression() = default;
    virtual int evaluate() const = 0;
    virtual void print() const = 0;
};

class IntegerLiteral : public Expression {
public:
    int value;
    explicit IntegerLiteral(int value) : value(value) {}
    int evaluate() const override;
    void print() const override;
};

class VariableExpression : public Expression {
public:
    std::string name;
    explicit VariableExpression(std::string name) : name(std::move(name)) {}
    int evaluate() const override;
    void print() const override;
};

class BinaryOperation : public Expression {
public:
    std::unique_ptr<Expression> left, right;
    char op;
    BinaryOperation(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right, char op)
        : left(std::move(left)), right(std::move(right)), op(op) {}
    int evaluate() const override;
    void print() const override;
};

class Instruction {
public:
    virtual ~Instruction() = default;
    virtual void execute() = 0;
};

class Assignment : public Instruction {
public:
    std::string variableName;
    std::unique_ptr<Expression> expression;
    Assignment(std::string variableName, std::unique_ptr<Expression> expression)
        : variableName(std::move(variableName)), expression(std::move(expression)) {}
    void execute() override;
};

class Print : public Instruction {
public:
    std::unique_ptr<Expression> expression;
    explicit Print(std::unique_ptr<Expression> expression)
        : expression(std::move(expression)) {}
    void execute() override;
};

#endif // IR_H
