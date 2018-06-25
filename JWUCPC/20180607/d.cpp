#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back
#define mp make_pair

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


int n;
VI w(301);
VI2 memo(301, VI(301));

int dp(int l, int r) {
    if(l == r) return 0;
    if(r-l == 1) return (std::abs(w[l]-w[r]) <= 1) ? 2 : 0;
    if(memo[l][r] != -1) return memo[l][r];

    int ans = 0;
    if(std::abs(w[l]-w[r]) <= 1) {
        int res = dp(l+1, r-1);
        if(res == r-l-1) {
            ans = 2 + res;
        }
    }
    for(int i=l; i<r; ++i) {
        ans = std::max(ans, dp(l, i) + dp(i+1, r));
    }
    return memo[l][r] = ans;
}

int main() {
    while(std::cin >> n, n != 0) {
        REP(i, n) {
            std::cin >> w[i];
        }
        memo.assign(301, VI(301, -1));
        std::cout << dp(0, n-1) << std::endl;
    }
}