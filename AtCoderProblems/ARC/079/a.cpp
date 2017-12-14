#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back

// Loop
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define RFOR(i,a,b) for(long i=(a);i>=(b);--i)

#define REP(i,a) for(long i=0;i<(a);++i)
#define RREP(i,a) for(long i=(a);i>=0;--i)

#define EACH(i,a) for(auto (i)=(a).begin(),_END=(a).end();i!=_END;++i)
#define REACH(i,a) for(auto (i)=(a).rbegin(),_END=(a).rend();i!=_END;++i)

//Algorithm
#define ALL(a) (a).begin(), a.end()
#define RALL(a) (a).rbegin(), a.rend()
#define EXIST(a,x) ((a).find(x)!=(a).end())
#define SORT(a) std::sort((a).begin(), (a).end())
#define UNIQUE(a) std::sort((a).begin(), a.end()), a.erase(std::unique((a).begin(), a.end()), a.end());
#define SUM(a) std::accumulate((a).begin(), (a).end(), 0);

//Setting
#define OPT std::cin.tie(0);std::ios::sync_with_stdio(false);

//debug message
bool debug = true;
#define MSG(s)   if(debug){std::cout << s << std::endl;}
#define DEBUG(x) if(debug){std::cout << "debug(" << #x << "): " << x << std::endl;}

//alias
typedef long long LL;
typedef std::vector<char> VC;
typedef std::vector<int>  VI;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;

typedef std::vector< VC > VC2;
typedef std::vector< VI > VI2;
typedef std::vector< VL > VL2;
typedef std::vector< VLL > VLL2;

typedef std::pair<int,int> PII;

//Common
typedef int Weight;
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

int N, M;

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


int main() {
    std::cin >> N >> M;

    g.resize(N);
    REP(i, M) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        Edge e1{a, b, 1}, e2{b, a, 1};
        g[a].pb(e1);
        g[b].pb(e2);
    }

    dijkstra(0);

    std::cout << (costs[N-1] == 2 ? "POSSIBLE" : "IMPOSSIBLE") << std::endl;
}