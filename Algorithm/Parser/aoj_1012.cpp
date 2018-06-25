#include <bits/stdc++.h>
#include <algorithm>

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

typedef std::set<int> SI;

std::set< char > ops;
std::map< char, SI > sets;
SI uni;

// Exp = Set {('u' | 'i' | 'd' | 's') Set}*
// Set = '(' Exp ')' | Name
// Name = setNames

SI parseExp(State* s);
SI parseSet(State* s);

void printSet(SI set) {
    EACH(it, set) {
        std::cout << " " << *it;
    }
}

SI parseExp(State* s) {
    SI set1 = parseSet(s);

    char op;
    while( op = s->seek(), op != -1 && op != ')') {
        s->eat(op);

        SI set2 = parseSet(s);
        if(op == 'u') {
            EACH(it, set2) {
                set1.insert(*it);
            }
        } else if(op == 'i') {
            SI set_i = set1;
            EACH(it, set1) {
                if(set2.count(*it) == 0) {
                    set_i.erase(*it);
                }
            }
            set1 = set_i;
        } else if(op == 'd') {
            EACH(it, set2) {
                set1.erase(*it);
            }
        } else if(op == 's') {
            SI set_u = set1;
            EACH(it, set2) {
                set_u.insert(*it);
            }

            SI set_i = set1;
            EACH(it, set1) {
                if(set2.count(*it) == 0) {
                    set_i.erase(*it);
                }
            }

            EACH(it, set_i) {
                set_u.erase(*it);
            }
            set1 = set_u;
        }
    }
    return set1;
}

SI parseSet(State* s) {
    if(s->seek() == '(') {
        s->eat('(');
        SI res = parseExp(s);
        s->eat(')');
        return res;
    }

    bool c = (s->seek() == 'c');
    if(c) s->eat('c');

    char name = s->getCh();
    if(sets.count(name) > 0) {
        SI set1 = sets[name];
        if(!c) {
            return set1;
        }

        SI set2 = uni;
        EACH(it, set1) {
            set2.erase(*it);
        }
        return set2;
    } else {
        return SI();
    }
}

int main () {
    ops.insert('u'), ops.insert('i'), ops.insert('d'), ops.insert('s');

    char c;
    int n;
    while(std::cin >> c >> n) {
        SI set;
        REP(i, n) {
            int x;
            std::cin >> x;
            set.insert(x);
            uni.insert(x);
        }
        sets[c] = set;

        while(std::cin >> c >> n) {
            if(c == 'R' && n == 0) break;
            set.clear();

            REP(i, n) {
                int x;
                std::cin >> x;
                set.insert(x);
                uni.insert(x);
            }
            sets[c] = set;
        }

        std::string e;
        std::cin >> e;
    
        State state = State {0, (int)e.length(), e};
        SI res = parseExp(&state);

        if(res.empty()) {
            std::cout << "NULL" << std::endl;
        } else {
            int i = 0;
            EACH(it, res) {
                if(i++ != 0) std::cout << ' ';
                std::cout << *it;
            }
            std::cout << std::endl;
        }
        sets.clear();
        uni.clear();
    }
}