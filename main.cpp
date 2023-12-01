#include "lexer.h"
#include "parser.h"
#include "ir.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <source file>\n";
        return 1;
    }

    std::ifstream sourceFile(argv[1]);
    if (!sourceFile.is_open()) {
        std::cerr << "Could not open source file: " << argv[1] << "\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << sourceFile.rdbuf();
    std::string sourceCode = buffer.str();

    Lexer lexer(sourceCode);
    auto tokens = lexer.tokenize();
    
    Parser parser(tokens);
    auto ir = parser.parse();
    
    // Assuming you have a function to execute your IR
    // executeIR(ir);

    return 0;
}
