#include <bits/stdc++.h>

// Loop
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define REP(i,a) for(long i=0;i<(a);++i)
#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)
//Algorithm
#define ALL(a) (a).begin(), a.end()
#define SORT(a) std::sort((a).begin(), (a).end())
#define UNIQUE(a) std::sort((a).begin(), a.end()), a.erase(std::unique((a).begin(), a.end()), a.end());

//alias
typedef long long LL;
typedef std::vector<char> VC;
typedef std::vector<int>  VI;

typedef std::vector< VC > VC2;
typedef std::vector< VI > VI2;

typedef std::pair<int,int> PII;

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

typedef std::pair<bool,int> RES;

bool parseQ(State* s);
RES parseE(State* s);
RES parseT(State* s);
RES parseF(State* s);
RES parseN(State* s);

bool parseQ(State* s) {
    RES eres1 = parseE(s);
    if(!eres1.first || s->seek() != '=') return false;
    s->eat('=');
    
    RES eres2 = parseE(s);
    if(!eres2.first || s->isNotEOF()) return false;

    return eres1.second == eres2.second;
}

//E ::= T|E+T|E−T
//E ::= T {(+|-) T}*
RES parseE(State* s) {
    RES tres = parseT(s);
    if(!tres.first) return tres;

    int ans = tres.second;
    while(s->seek() == '+' || s->seek() == '-') {
        char op = s->getCh();

        tres = parseT(s);
        if(!tres.first) return tres;

        ans += (op == '+' ? 1 : -1) * tres.second;
    }
    return std::make_pair(true, ans);
}

//T ::= F|T∗F
//T ::= F ('*' F)*
RES parseT(State* s) {
    RES fres = parseF(s);
    if(!fres.first) return fres;

    int ans = fres.second;
    while(s->seek() == '*') {
        s->eat('*');
        fres = parseF(s);
        if(!fres.first) return fres;

        ans *= fres.second;
    }
    return std::make_pair(true, ans);
}

RES parseF(State* s) {
    char c = s->seek();
    if(c == '0' || c == '1') return parseN(s);
    if(c == '-') {
        s->eat('-');
        auto fres = parseF(s);
        fres.second *= -1;
        return fres;
    }
    if(c == '(') {
        s->eat('(');
        auto eres = parseE(s);
        if(!eres.first || s->seek() != ')') {
            return std::make_pair(false, 0);
        }
        s->eat(')');
        return eres;
    }
    return std::make_pair(false, 0);
}

RES parseN(State* s) {
    if(s->seek() == '0' && (s->seek(1) == '0' || s->seek(1) == '1')) {
        return std::make_pair(false, 0);
    }

    int v = 0;
    while(s->isNotEOF()) {
        char c = s->seek();
        if(c != '0' && c != '1') {
            break;
        }
        s->getCh();

        v = (v << 1) + (int)(c - '0');
    }
    return std::make_pair(true, v);
}

VC symbol {{'0', '1', '+', '-', '*', '(', ')', '='}};
VI used(8, 0);
std::string chars;
int input_size;
int chars_size;

std::set< std::map<char,char> > pattern;
void dfs(int i, std::map<char,char>& map) {
    if(i >= chars_size) {
        pattern.insert(map);
        return;
    }
    if(std::find(ALL(symbol), chars[i]) != symbol.end()) {
        map[chars[i]] = chars[i];
        dfs(i+1, map);
    } else {
        REP(j, 8) {
            if(used[j] == 0) {
                used[j] = 1;
                map[chars[i]] = symbol[j];
                dfs(i+1, map);
                used[j] = 0;
            }
        }
    }
}

int main() {
    std::string input;
    std::cin >> input;
    input_size = input.size();

    chars = input;
    UNIQUE(chars);
    chars_size = chars.size();

    std::map<char,char> m;
    dfs(0, m);

    LL ans = 0;
    for(auto p: pattern) {
        std::string str = input;
        REP(i, input_size) {
            str[i] = p[str[i]];
        }

        State state = State{0, input_size, str};
        if(parseQ(&state)) {
            ans++;
        }

    }
    std::cout << ans << std::endl;
}