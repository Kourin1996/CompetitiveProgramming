#include<bits/stdc++.h>

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

const int MAX_N = 100000;

int N, M;
VI2 tree(MAX_N);

VI parent(MAX_N);
VI depth(MAX_N);
VI graph(MAX_N);
std::vector<bool> isMark(MAX_N, false);
std::vector<std::pair<char,int>> query(MAX_N);

//uf
int find(int x){
    if(parent[x] == x){
        return x;
    }else {
        return parent[x] = find(parent[x]);
    }
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(depth[x] > depth[y]){
        parent[x] = y;
    }else{
        parent[y] = x;
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

void dfs(int k) {
    for(int i: tree[k]) {
        if(graph[i] != -1) continue;
        depth[i] = depth[k] + 1;
        graph[i] = k;
        dfs(i);
    }
}

int main(){
    while(std::cin >> N >> M, N != 0 && M != 0) {
        REP(i, N) {
            parent[i] = i;
            depth[i] = 0;
            graph[i] = -1;
            isMark[i] = false;

            tree[i].clear();
            query.clear();
        }

        REP(i, N-1) {
            int a;
            std::cin >> a;
            --a;
            tree[i+1].push_back(a);
            tree[a].push_back(i+1);
        }

        isMark[0] = true;
        REP(i, M) {
            char q;
            int k;
            std::cin >> q >> k;
            --k;
            if(q == 'M') {
                if(isMark[k]) continue;
                isMark[k] = true;
                query.push_back(std::make_pair(q, k));
            } else {
                query.push_back(std::make_pair(q, k));         
            }
        }

        graph[0] = 0;
        dfs(0);

        REP(i, N) {
            if(!isMark[i]) {
                unite(graph[i], i);
            }
        }

        LL ans = 0;
        for(auto it=query.rbegin(), _END=query.rend(); it != _END; ++it) {
            if(it->first == 'Q') {
                ans += find(it->second) + 1;
            } else {
                unite(graph[it->second], it->second);
            }
        }
        std::cout << ans << std::endl;
    }
}