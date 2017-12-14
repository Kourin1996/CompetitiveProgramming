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

struct UnionFind {
  std::vector<int> par;
  std::vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    REP(i,n) par[i] = i;
  }

  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (sizes[x] < sizes[y]) std::swap(x, y);

    par[y] = x;
    sizes[x] += sizes[y];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int size(int x) {
    return sizes[find(x)];
  }
};

int N, K, L;
int main() {
    std::cin >> N >> K >> L;
    UnionFind uf1(N);
    UnionFind uf2(N);

    REP(i, K) {
        int p, q;
        std::cin >> p >> q;
        p--;
        q--;
        uf1.unite(p, q);
    }
    REP(i, L) {
        int r, s;
        std::cin >> r >> s;
        r--;
        s--;
        uf2.unite(r, s);
    }

    std::map< PII, int > map;
    REP(i, N) {
        int r1 = uf1.find(i);
        int r2 = uf2.find(i);
        map[std::make_pair(r1, r2)]++;
    }

    REP(i, N) {
        int r1 = uf1.find(i);
        int r2 = uf2.find(i);
        std::cout << (i == 0 ? "" : " ") << map[std::make_pair(r1, r2)];
    }
    std::cout << std::endl;
}