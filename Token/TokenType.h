#pragma once
#include <regex>
#include <string>

#define TOKEN_TYPE_QUANTITY 10

enum TokenType {
    FRACTION, NUMBER, STRING, BOOLEAN, BUILTIN, KEYWORD, SYMBOL, SPECIAL, OPERATOR, OTHER
};

extern const std::string TokenRegex[TOKEN_TYPE_QUANTITY];
extern const std::string TokenTypeNames[TOKEN_TYPE_QUANTITY];
