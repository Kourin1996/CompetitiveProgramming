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

template<class T> struct UnionFind {
    std::vector<T> data;
    UnionFind(T size): data(size, -1){};
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

int main(){
    int n, q;
    int c, x, y;

    std::cin >> n >> q;
    UnionFind<int> tree = UnionFind<int>(n);
    REP(i, q){
        std::cin >> c >> x >> y;
        if(c == 0){
            tree.unite(x,y);
        } else {
            std::cout << (tree.same(x,y) ? 1 : 0) << std::endl;
        }
    }
}