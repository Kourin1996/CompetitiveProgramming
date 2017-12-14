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

//Setting
#define OPT std::cin.tie(0);std::ios::sync_with_stdio(false);

//debug message
bool debug = true;
#define MSG(s)   if(debug){std::cout << s << std::endl;}
#define DEBUG(x) if(debug){std::cout << "debug(" << #x << "): " << x << std::endl;}

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
    bool isEOF() {
        return pos >= len;
    }
    bool isNotEOF() {
        return pos < len;
    }

    //backtrack
    void setBacktrack() {
        stack.push_front(pos);
    }
    bool backtrack() {
        std::cout << "backtrack:" << pos << " -> ";
        if(stack.empty()) {
            pos = 0;
            return false;
        }
        pos = stack.front();
        std::cout << pos << std::endl;
        stack.pop_front();
        return true;
    }

    //Character Type
    bool isDigit() {
        return isDigit(0);
    }
    bool isDigit(int offset) {
        char c = seek(offset);
        return (c == -1 ? false : (c >= '0' && c <= '9'));
    }
    bool isUpperAlpha() {
        return isUpperAlpha(0);
    }
    bool isUpperAlpha(int offset) {
        char c = seek(offset);
        return (c == -1 ? false : (c >= 'A' && c <= 'Z'));
    }
    bool isLowerAlpha() {
        return isLowerAlpha(0);
    }
    bool isLowerAlpha(int offset) {
        char c = seek(offset);
        return (c == -1 ? false : (c >= 'a' && c <= 'z'));
    }

    //getCharacter
    char getCh() {
        if(pos >= len) return -1;
        else {
            char c = str[pos];
            pos += 1;
            return c;
        }
    }
    char seek() {
        return pos < len ? str[pos] : -1;
    }
    char seek(int offset) {
        return ((pos + offset) < len) ? str[pos+offset] : -1;
    }

    //getString
    std::string lookAhead(int l) {
        return ((pos + l) < len) ? str.substr(pos, l) : ""; 
    }
    std::string res() {
        return ((pos) >= len ? "" : str.substr(pos));
    }
} State;

typedef struct ParseResult {
    bool flag;
    bool isVector;
    PII  value;
} RES;

const int MOD = 998244353;
RES number(State*);
RES expr(State*);
RES fact(State*);

RES number(State *s) {
    s->setBacktrack();
    std::cout << "number:" << s->res() << std::endl;
    if( s->isEOF() || !s->isDigit() ) {
        s->backtrack();
        return RES {false, false, std::make_pair(0,0)};
    }

    int value = 0;
    while(s->isDigit()) {
        char c = s->getCh();
        value *= 10;
        value += (int)(c - '0');
        value %= MOD;
    }
    return RES {true, false, std::make_pair(value, 0)};
}

RES expr(State* s) {
    s->setBacktrack();
    std::cout << "expr:" << s->res() << std::endl;
    if( s->isEOF() ) {
        return RES {false, false, std::make_pair(0,0)};
    }
    if( s->isDigit() ) {
        return number(s);
    }
    if( s->seek() != '(') {
        s->backtrack();
        return RES {false, false, std::make_pair(0,0)};
    }

    s->getCh(); // eat (
    RES res = fact(s);
    if(res.flag == false) {
        s->backtrack();
        return RES {false, false, std::make_pair(0,0)};
    }
    s->getCh(); // eat )

    return res;
}

RES fact(State* s) {
    s->setBacktrack();
    std::cout << "fact:" << s->res() << std::endl;
    if( s->isEOF() ) {
        return RES {false, false, std::make_pair(0,0)};
    }

    RES left = expr(s);

    if( (left.flag == false) || !((s->seek() == ',') || (s->seek() == '*')) ) {
        s->backtrack();
        return RES {false, false, std::make_pair(0,0)};
    }
    char op = s->getCh();
    RES right = expr(s);
    if( right.flag == false ) {
        s->backtrack();
        return RES {false, false, std::make_pair(0,0)};
    }
    //,
    if(op == ',') {
        if(left.isVector || right.isVector) return RES {false, false, std::make_pair(0,0)};
        return RES {true, true, std::make_pair(left.value.fst, right.value.fst)};
    }

    //*
    if(left.isVector && right.isVector) {
        //vec * vec
        LL value = ((LL)left.value.fst * right.value.fst) % MOD;
        value += ((LL)left.value.snd * right.value.snd) % MOD;
        value %= MOD;
        return RES {true, false, std::make_pair(value, 0)};
    } else if(!left.isVector && right.isVector) {
        //sca * vec
        int f = ((LL)left.value.fst * right.value.fst) % MOD;
        int s = ((LL)left.value.fst * right.value.snd) % MOD;
        return RES {true, true, std::make_pair(f, s)};
    } else if(left.isVector && !right.isVector) {
        int f = ((LL)left.value.fst * right.value.fst) % MOD;
        int s = ((LL)left.value.snd * right.value.fst) % MOD;
        return RES {true, true, std::make_pair(f, s)};
    }
    //sca * sca
    int value = ((LL)left.value.fst * right.value.fst) % MOD;
    return RES {true, false, std::make_pair(value, 0)};

}

/*
a ((1,2) * (3,4))
a (1,2)

*/

/*
<expr> ::= <num> | "(" <fact> ")"
<fact> ::= <expr> "," <expr> | <expr> "*" <expr>

<expr1> = ((1,2)*(3,4)) => (<fact1>)
<fact1> = <fact2> * <fact3>
<fact2> = 1 , 2
<fact3> = 3 , 4
*/

int main() {
    std::string s;
    std::cin >> s;
    int len = s.length();
    State state = {0, len, s};

    auto res = expr(&state);
    std::cout << res.value.fst << std::endl;
}

/*
((1,2)*(3,4))
*/