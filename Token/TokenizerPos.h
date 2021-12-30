#pragma once
#include <string>

class TokenizerPos {
public:
    int idx, ln, col;
    std::string code;

    TokenizerPos(int idx, int ln, int col, std::string code) : idx(idx), ln(ln), col(col), code(code) {};
    void advance(int n);
    TokenizerPos clone();
    std::string to_string();
};
