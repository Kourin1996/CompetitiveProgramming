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