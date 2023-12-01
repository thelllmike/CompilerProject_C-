#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ir.h"
#include <stdexcept>

class Parser {
private:
    std::vector<Token> tokens;
    size_t current = 0;

    Token advance() {
        if (!isAtEnd()) current++;
        return previous();
    }

    Token previous() {
        return tokens[current - 1];
    }

    bool isAtEnd() {
        return peek().type == TokenType::END_OF_FILE;
    }

    Token peek() {
        return tokens[current];
    }

    bool check(TokenType type) {
        if (isAtEnd()) return false;
        return peek().type == type;
    }

    bool match(std::initializer_list<TokenType> types) {
        for (TokenType type : types) {
            if (check(type)) {
                advance();
                return true;
            }
        }
        return false;
    }

    Token consume(TokenType type, const std::string &message) {
        if (check(type)) return advance();

        throw std::runtime_error(message);
    }

    // Recursive descent parsing methods follow...

public:
    Parser(const std::vector<Token> &tokens) : tokens(tokens) {}

    // Methods to parse different constructs...
};

#endif // PARSER_H
