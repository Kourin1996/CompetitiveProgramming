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

//Wardhall-Floyd
std::vector< std::vector<Weight> > g;
std::vector< std::vector<int> > trace;
void warshallFloyd() {
    int n = g.size();
    trace.resize(n, std::vector<int>(n, -1));
    REP(k, n) REP(i, n) REP(j, n) {
        g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
    }
}
const int INF = 1 << 29;

int N, M, R;
std::vector<int> r;
int main() {
    std::cin >> N >> M >> R;
    g.resize(N, std::vector<Weight>(N, WEIGHT_INF));
    REP(i, N) REP(j, N) {
        if(i == j) g[i][j] = 0;
        else       g[i][j] = INF;
    }
    r.resize(R);
    
    REP(i, R) {
        std::cin >> r[i];
        r[i]--;
    }
    REP(i, M) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        g[a][b] = c;
        g[b][a] = c;
    }

    warshallFloyd();

    int ans = INT_MAX;
    std::sort(ALL(r));
    do {
        int sum = 0;
        REP(i, R-1) {
            sum += g[r[i]][r[i+1]];
        }
        ans = std::min(ans, sum);
    } while(std::next_permutation(ALL(r)));

    std::cout << ans << std::endl;
}