#include "include/parser.h"
#include <include/ir.h>

// Example method to parse an expression - a placeholder for now
Expression* Parser::parseExpression() {
    // You would implement your expression parsing logic here
    // For now, we'll just return nullptr for the sake of the example
    return nullptr;
}

// Method to parse statements
std::vector<Statement*> Parser::parse() {
    std::vector<Statement*> statements;
    while (!isAtEnd()) {
        statements.push_back(parseStatement());
    }
    return statements;
}

// Method to parse a single statement
Statement* Parser::parseStatement() {
    if (match({TokenType::PRINT})) {
        return parsePrintStatement();
    }
    if (match({TokenType::IDENTIFIER})) {
        return parseAssignmentStatement();
    }

    // Handle parsing error: unexpected token
    throw std::runtime_error("Unexpected token.");
}

// Placeholder for parsing print statements
Statement* Parser::parsePrintStatement() {
    Expression* value = parseExpression();
    consume(TokenType::SEMICOLON, "Expect ';' after value.");
    return new PrintStatement(value);
}

// Placeholder for parsing assignment statements
Statement* Parser::parseAssignmentStatement() {
    Token name = previous();
    consume(TokenType::EQUAL, "Expect '=' after variable name.");
    Expression* value = parseExpression();
    consume(TokenType::SEMICOLON, "Expect ';' after expression.");
    return new AssignmentStatement(name, value);
}
