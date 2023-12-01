#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "Instruction.h"
#include <vector>
#include <memory>

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);

    // Parses the entire program and returns its intermediate representation
    std::unique_ptr<InstructionNode> parseProgram();

private:
    std::vector<Token> tokens;
    size_t current;  // Current position in the tokens vector

    // Utility functions
    bool isAtEnd() const;
    const Token& peek() const;
    const Token& previous() const;
    bool check(TokenType type) const;
    bool match(TokenType type);
    void advance();
    void error(const std::string& message);

    // Parsing methods for different constructs
    std::unique_ptr<InstructionNode> parseStatement();
    std::unique_ptr<InstructionNode> parseExpression();
    // ... Add more methods for other constructs
};

#endif // PARSER_H
