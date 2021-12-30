#include "Token/Token.h"
#include "Token/Tokenizer.h"
#include <fstream>
#include <iostream>

int main() {
    std::vector<Token> tokens;
    std::ifstream file;
    file.open("code.hj", std::ifstream::in);
    auto tokenizer = Tokenizer();
    tokens = (file >> tokenizer);
    file.close();
    std::cout << "Tokens: ";
    for(Token t : tokens) {
        std::cout << t.to_string();
    }
    std::cout << std::endl;
    return 0;
}
