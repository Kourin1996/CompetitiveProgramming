#include <bits/stdc++.h>

typedef long long LL;

typedef struct ParserState {
    int pos, len;
    std::string str;
    std::deque<int> stack;

    bool isEOF() {return pos >= len;}
    bool isNotEOF() {return pos < len;}

    char getCh() {
        return pos < len ? str[pos++] : -1;
    }
    char seek() {
        return pos < len ? str[pos] : -1;
    }
    char seek(int offset) {
        return (pos+offset) < len ? str[pos+offset] : -1;
    }
    std::string lookAhead(int l) {
        return str.substr(pos, l);
    }

    void setBackrack(){stack.push_front(pos);}
    bool backtrack(){
        if(stack.empty()) return false;
        pos = stack.front();
        stack.pop_front();
        return true;
    }

    bool isDigit(){return isDigit(0);}
    bool isDigit(int offset) {
        char c = seek(offset);
        return c != -1 && c >= '0' && c <= '9';
    }
    bool isUpperAlpha(){return isUpperAlpha(0);}
    bool isUpperAlpha(int offset) {
        char c = seek(offset);
        return c != -1 && c >= 'A' && c <= 'Z';
    }
    bool isLowerAlpha(){return isLowerAlpha(0);}
    bool isLowerAlpha(int offset) {
        char c = seek(offset);
        return c != -1 && c >= 'a' && c <= 'z';
    }
}State;

std::map<char,int> pri;
int bot = 0;

LL parseNumber(State*);
LL parse(State*);

LL calc(char op, LL left, LL right) {
    if(op == '+') return left + right;
    if(op == '-') return left - right;
    if(op == '*') return left * right;
    return assert(pri.count(op) > 0), -1;
}

LL parseNumber(State* state) {
    LL res = 0LL;
    while(state->isNotEOF() && state->isDigit()) {
        res *= 10;
        res += (int)(state->getCh() - '0');
    }
    return res;
}

LL parse(int level, State* state) {
    if(bot < level) {
        if(state->isDigit()) return parseNumber(state);

        state->getCh(); // eat (
        LL r = parse(0, state);
        state->getCh(); // eat )
        return r;
    }

    LL result = parse(level + 1, state);
    while(state->isNotEOF() && state->seek() != ')') {
        char ch = state->seek();
        if(pri[ch] < level) break;
        state->getCh(); //eat op

        LL res = parse(level + 1, state);
        result = calc(ch, result, res);

        if(state->isEOF()) break;
    }
    return result;
}

int main() {
    std::string S;
    std::cin >> S;
    int len = S.length();

    LL ans = std::numeric_limits<LL>::min();
    for(int i=0; i<27; ++i) {
        pri['+'] = i     % 3;
        pri['-'] = (i/3) % 3;
        pri['*'] = (i/9) % 3;
        bot = std::max(i%3, std::max((i/3)%3, (i/9)%3));

        State state = State{0, len, S};
        LL res = parse(0, &state);

        ans = std::max(ans, res);
    }
    std::cout << ans << std::endl;
    return 0;
}