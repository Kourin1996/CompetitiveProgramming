#include<bits/stdc++.h>

#define REP(i,a) for(long i=0;i<(a);++i)

typedef std::vector<int>  VI;
typedef std::vector< VI > VI2;

typedef struct {
    int from, dest;
    int cost;
} Edge;

int N, M;
VI2 g;
std::vector<Edge> edges;
const int inf = std::numeric_limits<int>::max() - 1;
int main() {
    std::cin >> N >> M;
    g.resize(N, VI(N, inf));
    REP(i, N) g[i][i] = 0;
    edges.resize(M);

    REP(i, M) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        
        edges[i].from = a;
        edges[i].dest = b;
        edges[i].cost = c;

        g[a][b] = c;
        g[b][a] = c;
    }

    REP(k, N) REP(i, N) REP(j, N) {
        if(g[i][k] == inf || g[k][j] == inf) continue;
        g[i][j] = std::min(g[i][j], g[i][k]+g[k][j]);
    }

    int ans = 0;
    for(auto e: edges) {
        if(g[e.from][e.dest] == e.cost) continue;
        else {
            bool f = true;
            REP(k, N) {
                if(g[k][e.dest] - g[k][e.from] == e.cost) {
                    f = false;
                    break;
                }
            }
            ans += (int)f;
        }
    }
    std::cout << ans << std::endl;

}