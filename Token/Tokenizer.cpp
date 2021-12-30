#include "Tokenizer.h"
#include "Token.h"
#include "TokenType.h"
#include "TokenizerPos.h"
#include "../Utils/StringUtils.h"
#include <regex>
#include <set>

void Tokenizer::advance(int n) {
    pos.advance(n);
    slice = code.substr(pos.idx);
    while(slice[0] == '\t' || slice[0] == ' ' || slice[0] == '\n') advance(1);
}

std::vector<Token> Tokenizer::create_tokens() {
    std::vector<Token> tokens = std::vector<Token>();
    while(slice.size()) {
        Token token(TokenType::OTHER, "What");
        bool foundToken = false;
        std::cmatch cm;

        for (int i = 0 ; i < TOKEN_TYPE_QUANTITY ; i++) {
            if(!std::regex_search(trim(slice).c_str(), cm, std::regex(TokenRegex[i]))) continue;
            token = Token((TokenType) i, std::string(cm[0]));
            tokens.push_back(token);
            foundToken = true;
            break;
        }

        if (!foundToken) {
            std::cout << "I hate myself (but not seriously :) )." << std::endl;
            return tokens;
        }
        advance(token.value.length());
    }
    return tokens;
}

std::vector<Token> operator>>(std::istream &is, Tokenizer &t) {
    is.seekg(0, is.end);
    int length = is.tellg();
    is.seekg(0, is.beg);

    char *buffer = new char[length];
    is.read(buffer, length);
    if (!is) throw;

    t.code = std::string(buffer);
    t.pos = TokenizerPos(0, 0, 0, t.code);
    t.slice = t.code;

    delete[] buffer;

    return t.create_tokens();
}
