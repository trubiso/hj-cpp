#pragma once
#include "TokenType.h"
#include <string>

class Token {
public:
    TokenType   type;
    std::string value;

    Token(TokenType type, std::string value) : type(type), value(value) {};
    std::string to_string();
};
