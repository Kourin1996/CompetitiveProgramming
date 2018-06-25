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

std::string T, P;
int main() {
    std::cin >> T >> P;

    auto rht = new RollingHash(), rhp = new RollingHash();
    rht->init(T);
    rhp->init(P);

    int tp = T.size(), lp = P.size();
    auto hashP = rhp->get_hash_pair(0, lp);
    for(int i=0; i<tp-lp+1; ++i) {
        auto hashT = rht->get_hash_pair(i, i + lp);
        if(hashP == hashT) {
            std::cout << i << std::endl;
        }
    }
}