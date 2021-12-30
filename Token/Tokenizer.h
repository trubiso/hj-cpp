#include "TokenizerPos.h"
#include "Token.h"
#include <vector>
#include <string>
#include <iostream>

class Tokenizer {
public:
    std::string code;
    TokenizerPos pos;
    std::string slice;

    Tokenizer() : code(""), pos(0, 0, 0, ""), slice("") {}
    void advance(int n);
    friend std::vector<Token> operator>>(std::istream &is, Tokenizer &t);
    std::vector<Token> create_tokens();
};
