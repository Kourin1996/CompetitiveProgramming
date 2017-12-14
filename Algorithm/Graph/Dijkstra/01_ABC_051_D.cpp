#define REP(i,n) for(int i=0; i<(n); ++i)
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

int N, M;
std::vector< std::vector<long long int > > a;
std::vector< std::vector<long long int > > b;


int main(void){
    std::cin >> N >> M;

    a.resize(N, std::vector<long long int>(N, 0));
    b.resize(N, std::vector<long long int>(N, LLONG_MAX));
    REP(i,N){
        b[i][i] = 0;
    }

    int f, t, c;
    REP(i,M){
        std::cin >> f >> t >> c;
        --f,--t;
        a[f][t] = a[t][f] = b[f][t] = b[t][f] = c;
    }

    REP(k,N){
        REP(i,N){
            REP(j,N){
                b[i][j] = std::min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            if(a[i][j] > b[i][j]){
                ++ans;
            }
        }
    }

    std::cout << ans << std::endl;
}
