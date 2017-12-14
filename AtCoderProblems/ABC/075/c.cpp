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
typedef std::vector<char> VC;
typedef std::vector< VC > VCC;
typedef std::vector<int>  VI;
typedef std::vector< VI > VII;
typedef std::vector<long> VL;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;
typedef std::pair<int,int> PII;

int N, M;
VII g;
std::vector< PII > data;

int dfs(int i, int d, int p) {
    if(data[i].fst != -1) {
        return data[i].snd;
    }

    data[i].fst = d;
    data[i].snd = d;
    EACH(it, g[i]) {
        if(*it == p) continue;
        int res = dfs(*it, d+1, i);
        data[i].snd = std::min(data[i].snd, res);
    }
    return data[i].snd;
}

int main() {
    std::cin >> N >> M;
    g.resize(N);
    data.resize(N);
    REP(i, N) {
        data[i].fst = -1;
        data[i].snd = -1;
    }

    int a, b;
    REP(i, M) {
        std::cin >> a >> b;
        a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0,0,-1);

    int ans = 0;
    REP(i, N) if(data[i].fst == data[i].snd) ans++;
    std::cout << std::max(0, ans-1) << std::endl;
}