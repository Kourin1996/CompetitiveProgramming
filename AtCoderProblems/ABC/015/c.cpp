#include<bits/stdc++.h>

#define REP(i,a) for(long i=0;i<(a);++i)

//alias
typedef long long LL;
typedef std::vector<int>  VI;
typedef std::vector< VI > VI2;
typedef std::pair<int,int> PII;
int N, K;
VI2 T;

bool dfs(int i, int x) {
    if(i == N) return x == 0;

    REP(j, K) {
        if( dfs(i+1, x ^ T[i][j]) ) {
            return true;
        }
    }
    return false;
}

int main() {
    std::cin >> N >> K;
    T.resize(N, VI(K));
    REP(i, N) REP(j, K) {
        std::cin >> T[i][j];
    }
    std::cout << (dfs(0,0) ? "Found" : "Nothing") << std::endl;
}