#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back

// Loop
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define RFOR(i,a,b) for(long i=(a);i>=(b);--i)

#define REP(i,a) FOR(i,0,a)
#define RREP(i,a) RFOR(i,a,0)

#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)
#define REACH(i,a) for(auto (i)=(a).rbegin(),_END=(a).rend();i!=_END;++i)

//Algorithm
#define ALL(a) (a).begin(), a.end()
#define RALL(a) (a).rbegin(), a.rend()
#define EXIST(a,x) ((a).find(x)!=(a).end())
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a), a.erase(std::unique(ALL(a)), a.end());

//Setting
#define OPT std::cin.tie(0);std::ios::sync_with_stdio(false);

//debug message
bool debug = true;
#define MSG(s)   if(debug){std::cout << s << std::endl;}
#define DEBUG(x) if(debug){std::cout << "debug(" << #x << "): " << x << std::endl;}

//alias
typedef long long LL;
typedef std::vector<char> VC;
typedef std::vector< VC > VCC;
typedef std::vector<int>  VI;
typedef std::vector< VI > VII;
typedef std::vector<long> VL;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;
typedef std::pair<int,int> PII;

std::string S;

LL solve(LL p) {
    LL rest = 0;
    LL ans = 0;
    int len = S.length();

    REP(i, len) {
        rest *= 10;
        rest += (S[i] - '0');
        if( ((p >> i) & 0x01) == 0x01 ) {
            ans += rest;
            rest = 0;
        }
    }
    ans += rest;
    return ans;
}

int main() {
    std::cin >> S;
    int len = S.length();
    LL sum = 0ll;
    REP(i, (1ll << (len-1))) {
        LL res = solve(i);
        sum += res;
    }
    std::cout << sum << std::endl;
}