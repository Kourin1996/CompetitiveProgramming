#include<bits/stdc++.h>

#define pb push_back
#define REP(i,a) for(long i=0;i<(a);++i)

typedef std::vector< int > VI;
typedef std::vector< VI > VI2;

int N, M;
VI2 path;
int main() {
    std::cin >> N >> M;
    path.resize(N);

    REP(i, M) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        path[a].pb(b);
        path[b].pb(a);
    }

    for(auto pl: path) {
        std::cout << pl.size() << std::endl;
    }
}