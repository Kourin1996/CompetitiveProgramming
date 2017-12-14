#define REP(i,n) for(int i=0; i<(n);++i)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

typedef struct EDGE{int from, to; long long int cost;} edge;

std::vector<edge> es;
std::vector<long long int> d;

int N,M;

bool solve(){
    d[0] = 0;
    REP(i,N){
        REP(j,M){
            edge e = es[j];
            if(d[e.from] != LLONG_MIN && d[e.to] < d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                if(i == N-1){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void){
    int a, b, c;

    std::cin >> N >> M;
    d.resize(N, LLONG_MIN);
    es.resize(M);

    REP(i,M){
        std::cin >> a >> b >> c;

        edge e;
        e.from = a-1;
        e.to   = b-1;
        e.cost = c;

        es[i] = e;
    }

    if(solve()){
        std::cout << "inf" << std::endl;
    }else{
        std::cout << d[N-1] << std::endl;
    }
}
