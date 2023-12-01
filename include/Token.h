// Token.h
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    INTEGER_LITERAL,
    PLUS,
    MINUS,
    // ... other token types
    TOKEN_EOF, // Renamed EOF to avoid conflict
};

struct Token {
    TokenType type;
    std::string lexeme;
    // ... other token properties
};

#endif // TOKEN_H
