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


template<class T>
struct LazySegTree {
    // tree: data structure
    // INF: initilize value
    // f: update function(old, new)
    // g: get function(parent, child1, child2)

    T INF;
    size_t N;
    std::vector<T> tree, lazy;
    std::vector<bool> lazyFlag;

    std::function<T(T,T)> F;
    std::function<T(T,T,T)> G;

    LazySegTree(size_t size, T inf, std::function<T(T,T)> f, std::function<T(T,T,T)> g) {
        INF = inf;
        F = f;
        G = g;

        N = 1;
        while( N < size ) {
            N <<= 1;
        }
        tree.resize(2*N-1, INF);
        lazy.resize(2*N-1, INF);
        lazyFlag.resize(2*N-1, false);
    }

    void lazyEval(size_t k, size_t l, size_t r) {
        if(lazyFlag[k]) {
            tree[k] += lazy[k] * (r-l);
            if(r - l > 1) {
                lazy[2*k+1] = F(lazy[2*k+1], lazy[k]);
                lazy[2*k+2] = F(lazy[2*k+2], lazy[k]);
                lazyFlag[2*k+1] = lazyFlag[2*k+2] = true;
            }
            lazy[k] = INF;
            lazyFlag[k] = false;
        }
    }

    void update(size_t a, size_t b, T x) {
        update(a, b, x, 0, 0, N);
    }
    void update(size_t a, size_t b, T x, size_t k, size_t l, size_t r) {
        lazyEval(k, l, r);
        if( r <= a || b <= l ) return;
        if( a <= l && r <= b ) {
            lazy[k] = F(lazy[k], x);
            lazyFlag[k] = true;
            lazyEval(k, l, r);
        } else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            tree[k] = G(tree[k], tree[2*k+1], tree[2*k+2]);
        }
    }

    T query(size_t a, size_t b) {
        return query(a, b, 0, 0, N);
    }
    T query(size_t a, size_t b, size_t k, size_t l, size_t r) {
        lazyEval(k, l, r);
        
        if( r <= a || b <= l ) {
            return INF;
        }
        if( a <= l && r <= b ) {
            return tree[k];
        } else {
            T vl = query(a, b, k*2+1, l, (l+r)/2);
            T vr = query(a, b, k*2+2, (l+r)/2, r);
            return G(tree[k], vl, vr);
        }
    }
    
    T get(size_t i) {
        return tree[i+N-1];
    }
    
    void debug() {
        std::cout << "------" << std::endl;
        size_t l = 0, r = 0;
        do {
            FOR(i, l, r+1) {
                if(i != l) std::cout << " ";
                if(tree[i] != INF) {
                    std::cout << "(" << tree[i] << ",";
                } else {
                    std::cout << "(,";
                }
                if(lazy[i] != INF) {
                    std::cout << lazy[i] << ")";
                }else{
                    std::cout << ")";
                }
            }
            std::cout << std::endl;
            l = r + 1;
            r = r * 2 + 2;
        }while(r <= 2*N - 1);
        std::cout << "------" << std::endl;
    }
};

int n, q;
int main() {
    std::cin >> n >> q;
    LazySegTree<long> st = LazySegTree<long>(n, 0L,[&](long a, long b){return a+b;}, [&](long p, long a, long b){return a+b;});

    REP(i, q) {
        int c;
        std::cin >> c;
        if(c == 0) {
            size_t s, t;
            long x;
            std::cin >> s >> t >> x;
            st.update(s-1, t, x);
        } else {
            size_t s, t;
            std::cin >> s >> t;
            std::cout << st.query(s-1, t) << std::endl;
        }
    }
}