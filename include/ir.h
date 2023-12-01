#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Abstract class for any expression in the IR
class Expression {
public:
    virtual ~Expression() = default;
    virtual int evaluate() const = 0;  // Pure virtual function for evaluation
    virtual void print() const = 0;    // Pure virtual function for printing
};

// Expression for integer literals
class IntegerLiteral : public Expression {
public:
    int value;

    explicit IntegerLiteral(int value) : value(value) {}
    int evaluate() const override {
        return value;
    }
    void print() const override {
        std::cout << value;
    }
};

// Expression for variables (assuming you need this)
class VariableExpression : public Expression {
public:
    std::string name;

    explicit VariableExpression(std::string name) : name(std::move(name)) {}
    int evaluate() const override {
        // Implement variable lookup and return its value
        return 0; // Replace with actual logic
    }
    void print() const override {
        std::cout << name;
    }
};

// Binary operation expression
class BinaryOperation : public Expression {
public:
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
    char op; // Operator: '+', '-', '*', '/'

    BinaryOperation(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right, char op)
        : left(std::move(left)), right(std::move(right)), op(op) {}
    int evaluate() const override {
        int leftValue = left->evaluate();
        int rightValue = right->evaluate();
        switch (op) {
            case '+': return leftValue + rightValue;
            case '-': return leftValue - rightValue;
            case '*': return leftValue * rightValue;
            case '/': return leftValue / rightValue;
            default:
                throw std::runtime_error("Unknown operator");
        }
    }
    void print() const override {
        std::cout << "(";
        left->print();
        std::cout << " " << op << " ";
        right->print();
        std::cout << ")";
    }
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
    void print() const {
        std::cout << variableName << " = ";
        expression->print();
        std::cout << ";" << std::endl;
    }
};

// Print instruction
class Print : public Instruction {
public:
    std::unique_ptr<Expression> expression;

    explicit Print(std::unique_ptr<Expression> expression)
        : expression(std::move(expression)) {}
    void print() const {
        std::cout << "print ";
        expression->print();
        std::cout << ";" << std::endl;
    }
};

// The entire IR for a program
class IRProgram {
public:
    std::vector<std::unique_ptr<Instruction>> instructions;

    // Add an instruction to the program
    void addInstruction(std::unique_ptr<Instruction> instruction) {
        instructions.push_back(std::move(instruction));
    }

    // Print all instructions in the program
    void print() const {
        for (const auto& instruction : instructions) {
            instruction->print();
        }
    }
};

int main() {
    // Create an IR program
    IRProgram program;

    // Create expressions and instructions
    std::unique_ptr<Expression> expr1 = std::make_unique<IntegerLiteral>(42);
    std::unique_ptr<Expression> expr2 = std::make_unique<IntegerLiteral>(7);
    std::unique_ptr<Expression> expr3 = std::make_unique<BinaryOperation>(
        std::move(expr1), std::move(expr2), '+'
    );

    std::unique_ptr<Instruction> assign = std::make_unique<Assignment>("result", std::move(expr3));
    std::unique_ptr<Instruction> print = std::make_unique<Print>(std::make_unique<VariableExpression>("result"));

    // Add instructions to the program
    program.addInstruction(std::move(assign));
    program.addInstruction(std::move(print));

    // Print the entire IR program
    program.print();

    return 0;
}
