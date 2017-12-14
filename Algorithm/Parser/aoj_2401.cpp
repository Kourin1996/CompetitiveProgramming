#include<bits/stdc++.h>

#define fst first
#define snd second
#define pb push_back

// Loop
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define REP(i,a) for(long i=0;i<(a);++i)
#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)

#define ALL(a) (a).begin(), a.end()
#define EXIST(a,x) ((a).find(x)!=(a).end())
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

bool parseEq(State*);
bool parseF(State*);

std::string S;
std::vector<char> vars;
int vars_size = 0;
std::map<char, bool> map;

bool parseEq(State* s) {
    bool f1 = parseF(s);
    s->eat('=');
    bool f2 = parseF(s);

    return f1 == f2;
}

bool parseF(State* s) {
    char c = s->getCh();

    if(c == 'T' || c == 'F') return c == 'T';
    if(c >= 'a' && c <= 'k') return map[c];

    if(c == '-') {
        return !parseF(s);
    }

    bool f1 = parseF(s);
    char op = s->getCh();
    if(op == '-' && s->seek() == '>') {
        s->eat('>');
        op = '>';
    }
    bool f2 = parseF(s);
    s->eat(')');

    if(op == '*') {
        return f1 && f2;
    } else if(op == '+') {
        return f1 || f2;
    } else if(op == '>') {
        return !(f1 && !f2);
    }
    std::cout << "Assert" << std::endl;
    return false;
}

int main() {
    std::string S;
    while(std::cin >> S, S != "#") {
        int len = S.length();
        State state = State{0, len, S};

        vars.clear();
        for(int i=0; i<len; ++i) {
            if(S[i] >= 'a' && S[i] <= 'k') {
                vars.pb(S[i]);
            }
        }
        UNIQUE(vars);
        vars_size = vars.size();

        map.clear();
        int p = (1 << vars_size);

        bool f = true;
        REP(i, p) {
            std::bitset<10> bit(i);
            REP(j, vars_size) {
                map[vars[j]] = bit[j];
            }

            state.pos = 0;
            if(!parseEq(&state)) {
                f = false;
                break;
            }
        }
        
        std::cout << (f ? "YES" : "NO") << std::endl;
    }
}