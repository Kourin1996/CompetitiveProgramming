#include <bits/stdc++.h>

typedef long long LL;
typedef std::pair<int,int> PII;

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

/*
    <program> := { <line> \n}*

    <line> := <declaration> | <assignment>
    <declaration> := <arrayname> '[' <number> ']'
    <assignment>  := <arrayname> '[' <expression> ']' '=' <expression>
    <expression>  := <number> | <arrayname> '[' <expression> ']'
    <number> := [0-9]+

    <array> := <alpha> '[' <number> ']'
*/

std::map<char, int > size;
std::map<char, std::map<int,int> > initialized;

int  parseNumber(State*);
PII  parseArray(State*);
PII  parseExpr(State*);
bool parseLine(State*);

bool isRange(int name, int index) {
    return size.count((char)name) > 0 && index < size[(char)name];
}
bool isSet(int name, int index) {
    return isRange((char)name, index) && initialized[(char)name].count(index) > 0;
}

void decl(int name, int len) {
    size[(char)name] = len;
}
bool set(int name, int index, int value) {
    if(!isRange((char)name, index)) return false;
    initialized[(char)name][index] = value;
    return true;
}
int get(int name, int index) {
    if(!isSet((char)name, index)) return -1;
    return initialized[(char)name][index];
}

int parseNumber(State *state) {
    int res = 0;
    while(state->isNotEOF() && state->isDigit()) {
        res *= 10;
        res += (int)(state->getCh() - '0');
    }
    return res;
}

PII parseArray(State *state) {
    int name = (int)state->getCh();
    state->getCh(); // eat [
    int num = parseNumber(state);
    state->getCh(); // eat ]
    return std::make_pair(name, num);
}

PII parseExpr(State *state) {
    if(state->isDigit()) return std::make_pair(parseNumber(state), -1);

    int name = (int)state->getCh();
    state->getCh(); // eat [
    PII sub = parseExpr(state);
    state->getCh(); // eat ]

    if(sub.first < 0) return std::make_pair(-1, 0);
    if(sub.second < 0) {
        //integer literal access
        return std::make_pair(name, sub.first);
    }
    if(!isSet(sub.first, sub.second)) return std::make_pair(-1, 0);

    return std::make_pair(name, get(sub.first, sub.second));
}

bool parseLine(State *state) {
    PII ary = parseExpr(state);
    if(ary.first < 0) return false;

    if(state->isNotEOF() && state->seek() == '=') {
        if(isRange(ary.first, ary.second) == false) return false;

        state->getCh();// eat =
        PII expr = parseExpr(state);
        if(expr.first < 0) return false;

        int val = expr.first;
        if(expr.second >= 0) {
            if(!isSet(expr.first, expr.second)) return false;
            val = get(expr.first, expr.second);
        }
        set(ary.first, ary.second, val);
    } else {
        decl(ary.first, ary.second);
    }
    return true;
}

int main() {
    std::string S;
    while(std::cin >> S && S[0] != '.') {
        int line = 0, res = -1;
        size.clear();
        initialized.clear();
        do {
            line++;
            State state = State{0, (int)S.length(), S};
            if(res == -1 && parseLine(&state) == false) {
                res = line;
            }
        }while(std::cin >> S && S[0] != '.');
        std::cout << std::max(res, 0) << std::endl;
    }
}
