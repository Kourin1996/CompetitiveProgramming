#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back

// Loop
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define RFOR(i,a,b) for(long i=(a);i>=(b);--i)

#define REP(i,a) FOR(i,0,a)
#define RREP(i,a) RFOR(i,a,0)

#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)
#define REACH(i,a) for(auto (i)=(a).rbegin(),_END=(a).rend();i!=_END;++i)

//Algorithm
#define ALL(a) (a).begin(), a.end()
#define RALL(a) (a).rbegin(), a.rend()
#define EXIST(a,x) ((a).find(x)!=(a).end())
#define SORT(a) sort(ALL(a))

//Setting
#define OPT std::cin.tie(0);std::ios::sync_with_stdio(false);

//debug message
bool debug = true;
#define MSG(s)   if(debug){std::cout << s << std::endl;}
#define DEBUG(x) if(debug){std::cout << "debug(" << #x << "): " << x << std::endl;}

//alias
typedef long long LL;
typedef std::vector<int> VI;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;
typedef std::pair<int,int> PII;

//Common
typedef long long Weight;
const Weight WEIGHT_INF = std::numeric_limits<Weight>::max()/4;

struct Edge {
    int src, dst;
    Weight weight;
};
bool operator<(const Edge& a, const Edge& b) {
    return (a.weight < b.weight);
}
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

int main(void){
    int v, e, r;
    std::cin >> v >> e >> r;
    g.resize(v);
    REP(i, e){
        int s, t, d;
        std::cin >> s >> t >> d;
        Edge edge{s, t, d};
        g[s].pb(edge);
    }

    bool res = bellmanFord(r);
    if(res){
        REP(i, v){
            if(costs[i] != WEIGHT_INF){
                std::cout << costs[i] << std::endl;
            } else {
                std::cout << "INF" << std::endl;
            }
        }
    } else {
        std::cout << "NEGATIVE CYCLE" << std::endl;
    }
}