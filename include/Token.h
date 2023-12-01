// Token.h
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    INTEGER_LITERAL,
    PLUS_SIGN,
    MINUS_SIGN,
    // ... other token types ...
};

struct Token {
    TokenType type;
    std::string text;

    Token(TokenType type, const std::string& text) : type(type), text(text) {}
};

#endif // TOKEN_H
