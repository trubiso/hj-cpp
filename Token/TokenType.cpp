#include "TokenType.h"

const std::string TokenRegex[TOKEN_TYPE_QUANTITY] = { 
    "^[\\s]*(?:-)?[0-9]+\\/(?:-)?[0-9]+",
    "^[\\s]*(?:-)?[0-9]+(?:\\.[0-9]+)?",
    "^[\\s]*\\\"(?:.*?)\\\"",
    "^[\\s]*(?:true|false)",
    "^[\\s]*(?:frac|num|void|string|frac|bool|array)\\s",
    "^[\\s]*(if|else|elif|while|for|in|function|return|class)\\s",
    "^[\\s]*[A-Za-z_][\\w]*",
    "^[\\s]*(?:[\\{\\}\\(\\)\\[\\];:]|=>|\\.\\.\\.|\\.)",
    "^[\\s]*(?:(?:==|<=|<|>=|>|!=)|(?:(?:\\*{2}|\\+|\\-|\\/|\\*)?=)|(?:\\+\\+|\\-\\-)|(?:\\*\\*|[+\\-\\/*\\=]))",
    "^[\\s]*(?:\\,)"
};

const std::string TokenTypeNames[TOKEN_TYPE_QUANTITY] = {
    "FRACTION", "NUMBER", "STRING", "BOOLEAN", "BUILTIN", "KEYWORD", "SYMBOL", "SPECIAL", "OPERATOR", "OTHER"
};
