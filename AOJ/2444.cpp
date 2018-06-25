#include <bits/stdc++.h>

struct RollingHash {
    typedef long long LL;
    typedef std::pair<long long, long long> hash_type;
    private:
        LL base1, base2;
        LL mod1, mod2;
        std::vector<LL> hash1, hash2;
        std::vector<LL> pow1, pow2;
    public:
        RollingHash(): base1(1009), base2(1013), mod1(1000000007), mod2(1000000009) {}

        void init(const std::string& s) {
            int N = s.size();

            hash1.assign(N+1, 0);
            hash2.assign(N+1, 0);
            pow1.assign(N+1, 1);
            pow2.assign(N+1, 1);

            for(int i=0; i<N; ++i) {
                hash1[i+1] = (hash1[i] + s[i]) * base1 % mod1;
                hash2[i+1] = (hash2[i] + s[i]) * base2 % mod2;
                pow1[i+1] = pow1[i] * base1 % mod1;
                pow2[i+1] = pow2[i] * base2 % mod2;
            }
        }

        inline LL get_hash1(int l, int r) {
            return ( (hash1[r] - hash1[l]*pow1[r-l]) % mod1 + mod1) % mod1;
        }

        inline LL get_hash2(int l, int r) {
            return ( (hash2[r] - hash2[l]*pow2[r-l]) % mod2 + mod2) % mod2;
        }

        hash_type get_hash_pair(int l, int r) {
            return std::make_pair(get_hash1(l, r), get_hash2(l, r));
        }
};

int n, m;
std::string s;
int main() {
    std::cin >> n >> m;
    std::cin >> s;

    auto rh = new RollingHash();
    rh->init(s);

    std::string query;
    std::set<RollingHash::hash_type> set;
    int l = 0, r = 0;
    for(int i=0; i<m; ++i) {
        std::cin >> query;
        if(query == "L++") {
            ++l;
        } else if(query == "L--") {
            --l;
        } else if(query == "R++") {
            ++r;
        } else {
            --r;
        }
        auto v = rh->get_hash_pair(l, r+1);
        set.insert(v);
    }
    
    std::cout << set.size() << std::endl;
}
