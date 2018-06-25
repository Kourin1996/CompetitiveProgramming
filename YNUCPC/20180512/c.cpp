#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back

// Loop
#define FOR(i,a,b) for(auto i=(a);i<(b);++i)
#define RFOR(i,a,b) for(auto i=(a);i>=(b);--i)

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


std::string str;
int len;

std::map<int,int> bracketTable;

int inline calc(char op, int l, int r) {
    return   op == '+' ? l + r
           : op == '-' ? l - r
           : op == '*' ? l * r
           :             l / r;
}

bool inline isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isOperatorContain(int l, int r) {
    int d = 0;
    for(int i=l; i<=r; ++i) {
        if(str[i] == '(') {
            ++d;
        }
        if(str[i] == ')') {
            --d;
        }
        if(d > 0) {
            continue;
        }

        if(isOperator(str[i])) {
            return true;
        }
    }
    return false;
}

bool isCloseBracket(int l, int r) {
    return (bracketTable.count(l) > 0 && bracketTable[l] == r);
}

std::map< std::pair<int,int>, std::set<int> > memo;
std::set<int> eval(int l, int r) {
    std::pair<int,int> p = std::make_pair(l, r);
    if(memo.count(p) > 0) {
        return memo[p];
    }

    std::set<int> ans;
    if(isCloseBracket(l, r)) {
        ans = eval(l+1, r-1);
    } else if(isOperatorContain(l, r)) {
        int i = l, d = 0; //depth
        while(i <= r) {
            if(str[i] == '(') {
                ++d;
            }
            if(str[i] == ')') {
                --d;
            }
            if(d > 0) {
                ++i;
                continue;
            }

            if(isOperator(str[i])) {
                char op = str[i];
                auto left  = eval(l, i-1);
                auto right = eval(i+1, r);
                for(auto x: left) {
                    for(auto y: right) {
                        if(op == '/' && y == 0) {
                            continue;
                        }
                        ans.insert(calc(op, x, y));
                    }
                }
            }
            ++i;
        }
    } else {
        int v = 0;
        int i = l;
        while(i <= r && str[i] != ')') {
            assert(str[i] >= '0' && str[i] <= '9');
            v *= 10;
            v += (str[i] - '0');
            ++i;
        }
        ans.insert(v);
    }
    memo.insert(std::make_pair(p, ans));
    return ans;
}

int main() {
    int i, j;
    while(std::cin >> str, str != "#") {
        memo.clear();
        bracketTable.clear();
        len = str.length();
        for(i=0; i<len; ++i) {
            if(str[i] != '(') continue;

            int d = 1;
            for(j=i+1; j < len; ++j) {
                if(str[j] == '(') {
                    ++d;
                } else if(str[j] == ')') {
                    --d;
                    if(d == 0) {
                        break;
                    }
                }
            }
            bracketTable.insert(std::make_pair(i, j));
        }

        auto pat = eval(0, len - 1);
        std::cout << pat.size() << std::endl;
    }
}