#include<bits/stdc++.h>

namespace std {
    template <>
    class hash<std::pair<int, int>> {
    public:
        size_t operator()(const std::pair<int, int>& x) const{
            return hash<int>()(x.first) ^ hash<int>()(x.second);
        }
    };
}

// Shrotening
#define fst first
#define snd second
#define pb push_back

// Loop
#define FOR(i,a,b) for(auto i=(a);i<(b);++i)
#define RFOR(i,a,b) for(auto i=(a);i>=(b);--i)

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

//alias
typedef long long LL;
typedef std::vector<int>  VI;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;

typedef std::pair<int,int> PII;
typedef std::pair<int,PII> PIII;

typedef long long Weight;
const Weight WEIGHT_INF = std::numeric_limits<Weight>::max()/4;

struct Edge {
    PII src, dst;
    Weight weight;
};
bool operator<(const Edge& a, const Edge& b) {
    return (a.weight < b.weight);
};
bool operator>(const Edge& a, const Edge& b) {
    return (a.weight > b.weight);
};
typedef std::vector<Edge> Edges;
typedef std::unordered_map<PII, Edges> Graph;

Graph g;
std::unordered_map<PII, Weight> costs;
std::vector<int> res;
int N, M;

void dijkstra(){
    costs.insert(std::make_pair(std::make_pair(1, 0), 0));
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> q;
    q.push((Edge){std::make_pair(-1, 0), std::make_pair(1, 0), 0});
    while(!q.empty()) {
        Edge e = q.top();
        q.pop();
        EACH(it, g[e.dst]) {
            if(costs.count(it->dst) == 0) {
                costs[it->dst] = e.weight + it->weight;
                if(it->dst.fst == N) {
                    res.pb(e.weight + it->weight);
                }
                q.push((Edge){it->src, it->dst, e.weight + it->weight});
            } else if(costs[it->dst] > e.weight + it->weight) {
                costs[it->dst] = e.weight + it->weight;
                if(it->dst.fst == N) {
                    res.pb(e.weight + it->weight);
                }
                q.push((Edge){it->src, it->dst, e.weight + it->weight});
            }
        }
    }
}

void inline makepath(PII a, PII b) {
    if(g.count(a) == 0) {
        g.insert(std::make_pair(a, std::vector<Edge>(0)));
    }
    g[a].pb(Edge{a, b, ((a.snd == 0 || b.snd == 0) ? 1 : 0)} );
    if(g.count(b) == 0) {
        g.insert(std::make_pair(b, std::vector<Edge>(0)));
    }
    g[b].pb(Edge{b, a, ((a.snd == 0 || b.snd == 0) ? 1 : 0)});
}

int main() {
    std::cin >> N >> M;
    REP(i, M) {
        int p, q, c;
        std::cin >> p >> q >> c;
        makepath(std::make_pair(p, c), std::make_pair(p, 0));
        makepath(std::make_pair(p, c), std::make_pair(q, c));
        makepath(std::make_pair(q, c), std::make_pair(q, 0));
    }
    dijkstra();

    SORT(res);
    int r = res[0];

    std::cout << std::max(1, r-1) << std::endl;
}