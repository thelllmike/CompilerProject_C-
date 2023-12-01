#include "parser.h"
#include "Token.h"
#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), current(0) {}

std::unique_ptr<InstructionNode> Parser::parseProgram() {
    std::vector<std::unique_ptr<InstructionNode>> instructions;

    while (!isAtEnd()) {
        instructions.push_back(parseStatement());
        // Handle the case where parsing a statement fails
    }

    return std::make_unique<InstructionNode>(std::move(instructions));
}

bool Parser::isAtEnd() const {
    return peek().type == TokenType::TOKEN_EOF;  // Using the renamed enumerator
}

const Token& Parser::peek() const {
    return tokens[current];
}

const Token& Parser::previous() const {
    return tokens[current - 1];
}

bool Parser::check(TokenType type) const {
    if (isAtEnd()) return false;
    return peek().type == type;
}

bool Parser::match(TokenType type) {
    if (check(type)) {
        advance();
        return true;
    }
    return false;
}

void Parser::advance() {
    if (!isAtEnd()) current++;
}

void Parser::error(const std::string& message) {
    // Error handling code
    throw std::runtime_error(message);
}

std::unique_ptr<InstructionNode> Parser::parseStatement() {
    // Implement based on your grammar
    // Example:
    // if (match(TokenType::IF)) return parseIfStatement();
    return nullptr;
}

std::unique_ptr<InstructionNode> Parser::parseExpression() {
    // Implement based on your grammar
    return nullptr;
}
