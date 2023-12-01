#include "lexer.h"

int main() {
    std::string sourceCode = "var x = 42;";
    Lexer lexer(sourceCode);
    const std::vector<Token>& tokens = lexer.getTokens();

    for (const auto& token : tokens) {
        std::cout << "Token: " << token.text << ", Type: " << static_cast<int>(token.type) << "\n";
    }

    return 0;
}
