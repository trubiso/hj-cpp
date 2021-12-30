#include "TokenizerPos.h"
#include <string>

void TokenizerPos::advance(int n) {
    for (int i = 0 ; i < n ; i ++) {
        idx++;
        col++;
        if (code[idx] == '\n') {
            col = 0;
            ln++;
        }
    }
}

TokenizerPos TokenizerPos::clone() {
    return TokenizerPos(idx, ln, col, code);
}

std::string TokenizerPos::to_string() {
    std::string out;
    out.append(std::to_string(ln));
    out.append(":");
    out.append(std::to_string(col));
    out.append(" (idx: ");
    out.append(std::to_string(idx));
    out.append(")");
    return out;
}
