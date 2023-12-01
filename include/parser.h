#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <vector>
#include "Token.h"      // Include the Token class header file
#include "Instruction.h" // Include the Instruction class header file

class Parser {
public:
    // Constructor takes a vector of Tokens
    Parser(const std::vector<Token>& tokens);

    // Parses the entire program and returns the root node of the instruction list
    std::unique_ptr<InstructionNode> parseProgram();

private:
    // Vector of tokens provided by the lexer
    const std::vector<Token>& tokens;

    // Current position in the tokens vector
    size_t current;

    // Helper method to check if the end of tokens is reached
    bool isAtEnd() const;

    // Helper method to return the current token without consuming it
    const Token& peek() const;

    // Helper method to consume and return the current token, then advance to next
    const Token& advance();

    // Method to parse an individual statement and return its instruction node
    std::unique_ptr<InstructionNode> parseStatement();

    // Method to parse an expression and return its instruction node
    std::unique_ptr<InstructionNode> parseExpression();

    // Methods for parsing different types of statements and expressions
    std::unique_ptr<InstructionNode> parsePrintStatement();
    std::unique_ptr<InstructionNode> parseAssignmentStatement();
    std::unique_ptr<InstructionNode> parseIfStatement();
    std::unique_ptr<InstructionNode> parseWhileStatement();
    // ... Other parsing methods for different constructs

    // Utility methods for error handling and checking tokens
    bool match(TokenType type);
    bool check(TokenType type) const;
    void error(const Token& token, const std::string& message);
    // ... Other utility methods
};

#endif // PARSER_H
