#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back

// Loop
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define RFOR(i,a,b) for(long i=(a);i>=(b);--i)

#define REP(i,a) for(long i=0;i<(a);++i)
#define RREP(i,a) for(long i=(a);i>=0;--i)

#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)
#define REACH(i,a) for(auto (i)=(a).rbegin(),_END=(a).rend();i!=_END;++i)

//Algorithm
#define ALL(a) (a).begin(), a.end()
#define RALL(a) (a).rbegin(), a.rend()
#define EXIST(a,x) ((a).find(x)!=(a).end())
#define SORT(a) std::sort((a).begin(), (a).end())
#define UNIQUE(a) std::sort((a).begin(), a.end()), a.erase(std::unique((a).begin(), a.end()), a.end());
#define SUM(a) std::accumulate((a).begin(), (a).end(), 0);

//alias
typedef long long LL;
typedef std::vector<char> VC;
typedef std::vector<int>  VI;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;

typedef std::vector< VC > VC2;
typedef std::vector< VI > VI2;
typedef std::vector< VL > VL2;
typedef std::vector< VLL > VLL2;

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

long MOD = 1000000007;
/*
expr   ::= term | expr sp ">>" sp term
term   ::= number | "S" sp "<" sp expr sp ">"
sp     ::= "" | sp " "
number ::= digit | number digit

expr ::= term (">>" term)*;
*/



long expr(State*);
long term(State*);
void sp(State*);
long number(State*);

int depth = 0;
long expr(State* s) {
    sp(s);
    long x = term(s);
    sp(s);

    while(s->seek() == '>' && s->seek(1) == '>') {
        s->setBacktrack();
        s->eat('>');
        s->eat('>');

        sp(s);

        long y = term(s);
        if(y < 0) {
            s->backtrack();
            return x;
        }
        s->delBacktrack();

        sp(s);

        int xl2 = std::log2(x);
        x = xl2 < y ? 0 : (x >> y);
    }

    return x;
}

long term(State* s) {
    sp(s);

    if(s->isDigit()) return number(s);
    if(s->seek() == 'S') {
        s->eat('S');
        sp(s);
        s->eat('<');
        sp(s);

        long e = expr(s);

        sp(s);
        if(s->seek() != '>') return -1;
        s->eat('>');

        return ((LL)e * e) % MOD;
    }
    return -1;
}

void sp(State* s) {
    while(s->isNotEOF() && s->seek() == ' ') {
        s->eat(' ');
    }
}

long number(State* s) {
    long val = 0;
    while(s->isDigit()) {
        val *= 10;
        val += (int)(s->getCh() - '0');
    }
    return val;
}

int main() {
    std::string S;
    while(std::getline(std::cin, S) && S != "#") {
        State state = State{0, (int)S.length(), S};
        long res = expr(&state);
        std::cout << res << std::endl;
    }

}
    
    