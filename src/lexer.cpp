#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <cctype>

enum class TokenType {
    IDENTIFIER, NUMBER, OPERATOR, END_OF_FILE, UNKNOWN
};

struct Token {
    TokenType type;
    std::string text;
    size_t line; // Optional: track the line number for error reporting
};

class Lexer {
private:
    std::string source;
    std::vector<Token> tokens;
    size_t start = 0; // Start position of the current token
    size_t current = 0; // Current position in the source
    size_t line = 1; // Current line in the source

    void addToken(TokenType type, const std::string &text) {
        tokens.push_back({type, text, line});
    }

    void tokenize() {
        while (!isAtEnd()) {
            start = current;
            tokenizeNext();
        }

        tokens.push_back({TokenType::END_OF_FILE, "", line});
    }

    bool isAtEnd() {
        return current >= source.length();
    }

    void tokenizeNext() {
        char c = advance();
        switch (c) {
            case '(': case ')': case '{': case '}':
            case ',': case '.': case '-': case '+':
            case ';': case '*':
                addToken(TokenType::OPERATOR, std::string(1, c));
                break;

            case ' ': case '\r': case '\t':
                // Ignore whitespace
                break;

            case '\n':
                line++;
                break;

            default:
                if (std::isdigit(c)) {
                    number();
                } else if (std::isalpha(c)) {
                    identifier();
                } else {
                    addToken(TokenType::UNKNOWN, std::string(1, c));
                }
                break;
        }
    }

    char advance() {
        return source[current++];
    }

    void number() {
        while (std::isdigit(peek())) advance();

        // Look for a fractional part
        if (peek() == '.' && std::isdigit(peekNext())) {
            // Consume the "."
            advance();

            while (std::isdigit(peek())) advance();
        }

        addToken(TokenType::NUMBER, source.substr(start, current - start));
    }

    void identifier() {
        while (std::isalnum(peek())) advance();

        addToken(TokenType::IDENTIFIER, source.substr(start, current - start));
    }

    char peek() {
        if (isAtEnd()) return '\0';
        return source[current];
    }

    char peekNext() {
        if (current + 1 >= source.length()) return '\0';
        return source[current + 1];
    }

public:
    Lexer(const std::string &source) : source(source) {
        tokenize();
    }

    const std::vector<Token>& getTokens() const {
        return tokens;
    }
};

#endif // LEXER_H
