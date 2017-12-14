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
#define UNIQUE(a) SORT(a), a.erase(std::unique(ALL(a)), a.end());

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

typedef std::vector< VC > VCC;
typedef std::vector< VI > VII;

typedef std::pair<int,int> PII;

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

int N, X;
Graph g;
VLL values;
std::map<LL, LL> table;

LL ans;
void dfs(int i, int p, LL v) {
    if(values[i] != -1) return;

    ans += table[v ^ X];
    table[v]++;

    values[i] = v;
    EACH(it, g[i]) {
        if(p != it->dst) {
            dfs(it->dst, i, v ^ it->weight);
        }
    }
}

int main() {
    std::cin >> N >> X;
    g.resize(N);
    values.resize(N, -1);

    int x, y, c;
    REP(i, N-1) {
        std::cin >> x >> y >> c;
        x--, y--;
        Edge e1{x, y, c};
        Edge e2{y, x, c};
        g[x].pb(e1);
        g[y].pb(e2);
    }
    dfs(0, -1, 0ll);

    std::cout << ans << std::endl;
}