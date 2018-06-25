

//Common
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

//Dijkstra
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

//Wardhall-Floyd
std::vector< std::vector<Weight> > g;

std::vector< std::vector<int> > trace;
void warshallFloyd() {
    int n = g.size();
    trace.resize(n, std::vector<int>(n, -1));
    REP(k, n) REP(i, n) REP(j, n) {
        if(g[i][k] == WEIGHT_INF || g[k][j] == WEIGHT_INF){
            continue;
        }
        g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
    }
}
