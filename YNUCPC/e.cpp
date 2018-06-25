#include <bits/stdc++.h>
#define REP(i,a) for(long i=0;i<(a);++i)
#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)

typedef double Weight;
const Weight WEIGHT_INF = std::numeric_limits<Weight>::max();
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
Graph g;
std::vector<Weight> costs;
std::vector<int> trace;
void dijkstra(int start){
    int n = g.size();
    costs.resize(n, WEIGHT_INF);
    costs[start] = 0;
    trace.resize(n, -2);

    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> q;
    q.push((Edge){-1, start, 0});
    while(!q.empty()) {
        Edge e = q.top();
        q.pop();

        if(trace[e.dst] != -2) continue;
        trace[e.dst] = e.src;
        EACH(it, g[e.dst]) {
            if(costs[it->dst] > e.weight + it->weight){
                costs[it->dst] = e.weight + it->weight;
                q.push((Edge){it->src, it->dst, e.weight + it->weight});
            }
        }
    }
}

int xs, ys, xt, yt;
int N;
std::vector<int> x, y, r;

int main() {
    int i, j, k;
    double w;

    std::cin >> xs >> ys >> xt >> yt;
    std::cin >> N;

    x.resize(N+2), y.resize(N+2), r.resize(N+2);
    x[0] = xs;   y[0] = ys;   r[0] = 0;
    for(i=1; i<=N; ++i) {
        std::cin >> x[i] >> y[i] >> r[i];
    }
    x[N+1] = xt; y[N+1] = yt; r[N+1] = 0;

    g.resize(N+2);
    for(i = 0; i < N+2; ++i) {
        for(j = 0; j < N+2; ++j) {
            double d = (i == j) ? 0.0 : std::max(0.0, std::sqrt(std::pow(1.*x[i]-x[j], 2.0) + std::pow(1.*y[i]-y[j], 2.0)) - (r[i] + r[j]));
            g[i].push_back(Edge{i, j, d});
        }
    }
    
    dijkstra(0);
    std::cout << std::fixed << std::setprecision(10) << costs[N+1] << std::endl;
}