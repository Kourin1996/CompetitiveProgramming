#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

const int MAX_N = 1e5 + 5;
const int MOD   = 1e9 + 7;

int N;
std::vector< int > G[ MAX_N ];
int dp[ MAX_N ][ 2 ];

int dfs( int u, int fa, int fc ){
    if( dp[ u ][ fc ] != -1 ) return dp[ u ][ fc ];

    int w = 1, b = ( fc == -1 || fc == 0 );
    for( int v : G[u] ){
        if( v == fa ) continue;

        int wch = dfs( v, u, 0 );
        int bch = dfs( v, u, 1 );

        w = ( (long long int)w * wch ) % MOD;
        b = ( (long long int)b * bch ) % MOD;
    }
    return ( dp[ u ][ fc ] = w + b ) %= MOD;
}

void solve(){
    memset( dp, -1, sizeof(dp) );
    std::cout << dfs( 1, -1, -1 ) << std::endl;
}

int main(void){
    std::cin >> N;
    for( int i=0; i<N-1; ++i ){
        int u, v;
        std::cin >> u >> v;

        G[ u ].push_back( v );
        G[ v ].push_back( u );
    }
    solve();
    return 0;
}
