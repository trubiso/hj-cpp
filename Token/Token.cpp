#include "Token.h"
#include "TokenType.h"
#include <string>

std::string Token::to_string() {
    std::string out = "<";
    std::string type_name = TokenTypeNames[type];
    out.append(type_name.substr(0, 2));
    out.append(":");
    out.append(value);
    out.append(">");
    return out;
}
