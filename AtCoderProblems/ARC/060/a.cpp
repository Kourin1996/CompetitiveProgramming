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
#define SORT(a) sort(ALL(a))

//Setting
#define OPT std::cin.tie(0);std::ios::sync_with_stdio(false);

//debug message
#define MSG(s)   if(debug){std::cout << s << std::endl;}
#define DEBUG(x) if(debug){std::cout << "debug(" << #x << "): " << x << std::endl;}

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

//alias
using LL  = long long;
using VI  = std::vector<int>;
using VII = std::vector< std::vector<int> >;
using VL  = std::vector<long>;
using VL2 = std::vector<long long>;
using VL2L2 = std::vector< VL2 >;
using PII = std::pair<int,int>;

bool debug = true;

int N, A;
VI x;

int main(void){
    OPT;
    std::cin >> N >> A;
    x.resize(N);
    REP(i,N){
        std::cin >> x[i];
    }

    std::vector< VL2L2 > dp(N+1, VL2L2(N+1, VL2(N*A + 10, 0)));
    dp[0][0][0] = 1;
    REP(i,N){
        REP(j,N){
            REP(k, N*A){
                if( k+x[i] <= N*A ){
                    dp[i+1][j+1][k+x[i]] += dp[i][j][k];
                }
                dp[i+1][j][k] += dp[i][j][k];
            }
        }
    }

    LL ans = 0;
    FOR(i, 1, N+1){
        ans += dp[N][i][i*A];
    }
    std::cout << ans << std::endl;
}
