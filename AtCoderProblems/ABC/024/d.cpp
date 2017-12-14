#include<bits/stdc++.h>

#define REP(i,a) for(long i=0;i<(a);++i)
#define FOR(i,a,b) for(long i=(a);i<(b);++i)

typedef std::vector<int>  VI;
typedef std::vector< VI > VI2;

const int MOD = 1e9 + 7;

//nHr = (n+r-1)Cr
int main() {
    int n, k;
    std::cin >> n >> k;

    int l = n + k - 1;
    int r = k;

    VI2 C(l+1, VI(l+1, 0));
    REP(i, l+1) {
        C[i][0] = C[i][i] = 1;
    }
    FOR(i, 1, l+1) FOR(j, 1, i) {
        C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
    std::cout << C[l][r] << std::endl;
}