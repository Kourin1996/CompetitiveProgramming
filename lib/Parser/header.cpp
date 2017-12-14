typedef struct ParseState {
    int pos;
    int len;
    std::string str;
    std::deque<int> stack;

    //EOF
    bool isEOF() { return pos >= len; }
    bool isNotEOF() { return pos < len; }

    //advance
    void eat(char ch) {
        assert(pos < len && str[pos] == ch);
        pos++;
    }
    char getCh() {
        assert(pos < len);
        return pos < len ? str[pos++] : -1; 
    }
    //lookahead
    char seek() {
        return pos < len ? str[pos] : -1; 
    }
    char seek(int offset) {
        return (pos+offset) < len ? str[pos+offset] : -1;
    }

    //backtrack
    void setBacktrack() { stack.push_front(pos); }
    void delBacktrack() {
        assert(!stack.empty());
        stack.pop_front();
    }
    void backtrack() {
        assert(!stack.empty());
        pos = stack.front();
        stack.pop_front();
    }

    //test
    bool isDigit() {
        return isDigit(0);
    }
    bool isDigit(int offset) {
        char c = seek(offset);
        return c >= '0' && c <= '9';
    }
    bool isUpperAlpha() {
        return isUpperAlpha(0);
    }
    bool isUpperAlpha(int offset) {
        char c = seek(offset);
        return c >= 'A' && c <= 'Z';
    }
    bool isLowerAlpha() {
        return isLowerAlpha(0);
    }
    bool isLowerAlpha(int offset) {
        char c = seek(offset);
        return c >= 'a' && c <= 'z';
    }

    //test2
    bool isAlpha() {
        return isLowerAlpha(0) || isUpperAlpha(0);
    }
    bool isAlpha(int offset) {
        return isLowerAlpha(offset) || isUpperAlpha(offset);
    }
    bool isAlphaNum() {
        return isLowerAlpha(0) || isUpperAlpha(0) || isDigit(0);
    }
    bool isAlphaNum(int offset) {
        return isLowerAlpha(offset) || isUpperAlpha(offset) || isDigit(offset);
    }
} State;

typedef struct ParseResult {
    bool flag;
    bool isVector;
    PII  value;
} RES;