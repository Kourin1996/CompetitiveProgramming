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

    ParseState(int p, int l, std::string s) {
        pos = p;
        len = l;
        str = s;
    }
    bool isEOF() {
        return pos >= len;
    }
    bool isNotEOF() {
        return pos < len;
    }
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
    std::string lookAhead(int l) {
        return ((pos + l) < len) ? str.substr(pos, l) : ""; 
    }
    std::string remain() {
        return pos < len ? str.substr(pos) : "";
    }
} State;

bool Expr(State*);
bool Clas(State*);
char Lite(State*);

/*
<Expr>    = '(' <Clause> ')' | '(' <clause> ')|(' <Expression> ')'
<Clause>  = <Literal> '&' <Literal> '&' <Literal>
<Literal> = <variable> | '~'<variable>

<Expr> = '(' <Clause> ')' {'|(' <Expression> ')'}*
*/

bool Expr(State* s) {
    while(s->isNotEOF()) {
        s->getCh(); // Eat (
        
        if( Clas(s) ) return true;

        if(s->isEOF()) break;
        s->getCh(); // Eat |
    }
    return false;
}

bool Clas(State* s) {
    std::set< std::pair<bool, char> > set;
    for(int i=0; i<3; ++i) {
        bool flag = true;
        if(s->seek() == '~') {
            flag = false;
            s->getCh(); //Eat ~
        }
        char c = s->getCh();

        if(set.count(std::make_pair(!flag, c)) > 0) {
            return false;
        }
        set.insert(std::make_pair(flag, c));

        s->getCh();
    }
    return true;
}

int main() {
    std::string s;
    while( std::cin >> s, !(s.length() == 1 && s[0] == '#') ) {
        State state = State(0, s.length(), s);
        bool res = Expr(&state);
        std::cout << (res ? "yes" : "no") << std::endl;
    }
}