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
        bool found_token = false;
        std::smatch sm;
        std::string trimmed_slice = trim(slice);

        for (int i = 0 ; i < TOKEN_TYPE_QUANTITY ; i++) {
            std::regex current_regex = std::regex(TokenRegex[i]);
            if(!std::regex_search(trimmed_slice, sm, current_regex, std::regex_constants::match_continuous)) continue;
            std::string results = sm.str();
            token = Token((TokenType) i, trim(results));
            tokens.push_back(token);
            found_token = true;
            break;
        }

        if (!found_token) {
            std::cout << "I hate myself (but not seriously (or maybe seriously since I'm the program that's failing and shouldn't be plus I'm just a simple C++ program that is apparently self-conscious and is failing at such a simple task as tokenizing a piece of code...) :) )." << std::endl;
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
