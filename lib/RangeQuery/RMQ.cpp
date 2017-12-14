//Square division
template<class T>
struct RMQ {
    T sz;
    T sq;

    std::vector<T> data;
    std::vector<T> bucket;
    RMQ(T size){
        sq = std::ceil(std::sqrt(size));
        sz = size;
        data.resize(size, -1);
        bucket.resize(sq, -1);
    }  
    RMQ(T size, T init): data(size, init){
        sq = std::ceil(std::sqrt(size));
        sz = size;
        data.resize(size, init);
        bucket.resize(sq, init);
    }
    void update(T i, T x) {
        data[i] = x;
        T minVal = data[i];
        T k = i / sq;
        FOR(j,k*sq,(k+1)*sq) {
            minVal = std::min(minVal, data[j]);
        }
        bucket[k] = minVal;
    }
    T find(T s, T t) {
        if(s == t) return data[s];
        T val = (1LL << 31) - 1;
        REP(i, sq) {
            T l = i*sq, r = (i+1)*sq;
            if(r <= s || t <= l) {
                continue;
            }
            
            if(s <= l && r <= t) {
                val = std::min(val, bucket[i]);
            } else {
                FOR(j, std::max(s, l), std::min(t, r) + 1) {
                    val = std::min(val, data[j]);
                }
            }
        }
        return val;
    }
};