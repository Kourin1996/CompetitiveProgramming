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

/*
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

Graph g;
Edges msTree;
Weight prim(int r) {
    int n = g.size();
    Edges T;
    Weight total = 0;
    std::vector<bool> visited(n, false);
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge> > que;
    que.push(Edge{-1, r, 0});
    while(!que.empty()) {
        Edge e = que.top();
        que.pop();
        if(visited[e.dst]) continue;
        T.push_back(e);
        total += e.weight;
        visited[e.dst] = true;
        for(auto ce: g[e.dst]){
            if(!visited[ce.dst]) {
                que.push(ce);
            }
        }
    }
    return total;
}

int V, E;
int main() {
    std::cin >> V >> E;
    g.resize(V);
    REP(i, E) {
        int s, t, w;
        std::cin >> s >> t >> w;
        Edge e1{s, t, w};
        Edge e2{t, s, w};
        g[s].pb(e1);
        g[t].pb(e2);
    }
    auto res = prim(0);
    std::cout << res << std::endl;
}
*/

//Kruskal
template<class T> struct UnionFind {
    std::vector<T> data;
    UnionFind(){};
    UnionFind(T size): data(size, -1){};
    void init(T size) {
        data.resize(size, -1);
    }
    T root(T x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    bool same(T x, T y) {
        return root(x) == root(y);
    }
    T size(T x) {
        return -data[root(x)];
    }
    bool unite(T x, T y) {
        x = root(x);
        y = root(y);
        if(x != y){
            if(data[y] < data[x]){
                std::swap(x, y);
            }
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
};

//common
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

Edges edges;
UnionFind<int> uf;
Edges msTree;
Weight kruskal(int n, int r) {
    std::sort(edges.begin(), edges.end());
    int cnt = 0;
    Weight total = 0;
    uf.init(n);
    msTree.reserve(n-1);
    for(auto e: edges) {
        if(cnt >= n-1) break;
        if(uf.unite(e.src, e.dst)) {
            total += e.weight;
            msTree.pb(e);
            cnt++;
        }
    }
    return total;
}
int V, E;
int main() {
    std::cin >> V >> E;
    edges.reserve(2*E);
    REP(i, E) {
        int s, t, w;
        std::cin >> s >> t >> w;
        Edge e1{s,t,w};
        Edge e2{t,s,w};
        edges.pb(e1);
        edges.pb(e2);
    }
    std::cout << kruskal(V, 0) << std::endl;
}
