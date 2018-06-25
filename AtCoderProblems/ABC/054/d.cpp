#include<bits/stdc++.h>

#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define REP(i,a) for(long i=0;i<(a);++i)

typedef std::vector<int>  VI;
typedef std::vector< VI > VI2;
typedef std::vector< VI2 > VI3;

int N, A, B;
VI a(40), b(40), c(40);
const int inf = 1000000;
VI3 dp(41, VI2(401, VI(401, inf)));

int main() {
    std::cin >> N >> A >> B;
    REP(i, N) {
        std::cin >> a[i] >> b[i] >> c[i];
    }

    int maxcap = N*10;
    dp[0][0][0] = 0;

    REP(k, N) REP(i, maxcap) REP(j, maxcap) {
        if(dp[k][i][j] == inf) continue;
        dp[k+1][i][j]           = std::min(dp[k+1][i][j], dp[k][i][j]);
        dp[k+1][i+a[k]][j+b[k]] = std::min(dp[k+1][i+a[k]][j+b[k]], dp[k][i][j]+c[k]);
    }

    int ans = inf;
    bool f = false;
    FOR(i, 1, maxcap) FOR(j, 1, maxcap){
        if(i*B == j*A) {
            f = true;
            ans = std::min(ans, dp[N][i][j]);
        }
    }

    if(ans == inf) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << ans << std::endl;
    }
}