#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back

#define REP(i,a) for(long i=0;i<(a);++i)
#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)

typedef long long Weight;
const Weight WEIGHT_INF = std::numeric_limits<Weight>::max()/4;

struct Edge {
    int src, dst;
    Weight weight;
};
bool operator<(const Edge& a, const Edge& b) {
    return (a.weight < b.weight);
};
bool operator>(const Edge& a, const Edge& b) {
    return (a.weight > b.weight);
};
typedef std::vector<Edge> Edges;
typedef std::vector<Edges> Graph;

//Bellman-ford
Graph g;
std::vector<Weight> costs;
std::vector<int> trace;
bool bellmanFord(int start) {
    int n = g.size();
    costs.resize(n, WEIGHT_INF);
    trace.resize(n, -2);
    costs[start] = 0;
    trace[start] = -1;

    bool negativeCycle = false;
    REP(k, n) REP(i, n) if(costs[i] != WEIGHT_INF) EACH(e, g[i]) {
        if(costs[e->dst] > costs[e->src] + e->weight){
            costs[e->dst] = costs[e->src] + e->weight;
            trace[e->dst] = e->src;
            if(k == n-1){
                costs[e->dst] = -WEIGHT_INF;
                negativeCycle = true;
            }
        }
    }
    return !negativeCycle;
}

int N, M;
int main() {
    std::cin >> N >> M;
    g.resize(N);
    REP(i, M) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a -= 1;
        b -= 1;
        c *= -1;
        
        Edge e{a, b, c};
        g[a].pb(e);
    }
    bellmanFord(0);
    if(costs[N-1] == -WEIGHT_INF) {
        std::cout << "inf" << std::endl;
    } else {
        std::cout << -costs[N-1] << std::endl;
    }
}