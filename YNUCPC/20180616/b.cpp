#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back
#define mp std::make_pair

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
typedef std::pair<int,int> PII;

typedef std::vector<char> VC;
typedef std::vector<int>  VI;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;
typedef std::vector<PII> VPII;

typedef std::vector< VC > VC2;
typedef std::vector< VI > VI2;
typedef std::vector< VL > VL2;
typedef std::vector< VLL > VLL2;

int N, M;
VI2 b(21, VI(100001, 0));

VI memo(1 << 20, -1);
int dp(int idx, int bit){
    if(idx == N) return 0;
    if(memo[bit] != -1) return memo[bit];

    int ret = std::numeric_limits<int>::max();
    FOR(i, 1, M+1) {
        if( (bit&1 << (i-1)) == 0 ){
            int num = N - b[i][N];
            int oth = b[i][idx+num] - b[i][idx];
            ret = std::min(ret, dp(idx + num, bit|1<<(i-1)) + oth);
        }
    }
    return (memo[bit] = ret);
}

int main(){
    std::cin >> N >> M;
    FOR(i, 1, N+1) {
        int a;
        std::cin >> a;
        FOR(j, 1, M+1) {
            if(j != a) b[j][i]++;
            b[j][i] += b[j][i-1];
        }
    }
    std::cout << dp(0, 0) << std::endl;
}