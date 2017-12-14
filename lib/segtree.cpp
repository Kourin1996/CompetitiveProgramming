template<class T>
struct SegTree {
    // tree: data structure
    // INF: initilize value
    // f: update function(old, new)
    // g: get function(child1, child2)

    T INF;
    size_t N;
    std::vector<T> tree;

    std::function<T(T,T)> F;
    std::function<T(T,T)> G;

    SegTree(size_t size, T inf, std::function<T(T,T)> f, std::function<T(T,T)> g) {
        INF = inf;
        F = f;
        G = g;

        N = 1;
        while( N < size ) {
            N <<= 1;
        }
        tree.resize(2*N-1, INF);
    }

    void update(int i, int x) {
        i += N - 1;
        tree[i] = F(tree[i], x);
        while(i > 0) {
            i = (i-1)/2;
            tree[i] = G(tree[i*2+1],tree[i*2+2]);
        }
    }

    T query(size_t a, size_t b) {
        auto x = query(a, b, 0, 0, N);
        return x;
    }
    T query(size_t a, size_t b, size_t k, size_t l, size_t r) {
        if( r <= a || b <= l ) {
            return INF;
        }
        if( a <= l && r <= b ) {
            return tree[k];
        } else {
            T vl = query(a, b, k*2+1, l, (l+r)/2);
            T vr = query(a, b, k*2+2, (l+r)/2, r);
            return G(vl, vr);
        }
    }

    void debug() {
        std::cout << "------" << std::endl;
        std::cout << tree[0] << std::endl;
        size_t r = 0;
        while(r < N-1) {
            size_t ch = r*2+2;
            FOR(i, r+1, ch+1) {
                if(i != r+1) std::cout << " ";
                std::cout << tree[i];
            }
            std::cout << std::endl;
            r = ch;
        }
        std::cout << "------" << std::endl;
    }
};

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
            tree[k] = F(tree[k], lazy[k]);
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
            lazy[k] = true;
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