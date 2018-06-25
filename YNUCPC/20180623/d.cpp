#include<bits/stdc++.h>

// Shrotening
#define fst first
#define snd second
#define pb push_back
#define mp std::make_pair

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

#define fcout(n) std::cout << std::fixed << std::setprecision((n))

//Setting
#define OPT std::cin.tie(0);std::ios::sync_with_stdio(false);

//debug message
bool debug = true;
#define MSG(s)   if(debug){std::cout << s << std::endl;}
#define DEBUG(x) if(debug){std::cout << "debug(" << #x << "): " << x << std::endl;}

//alias
typedef long long LL;
typedef std::pair<int,int> PII;

typedef std::vector<char> VC;
typedef std::vector<int>  VI;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;
typedef std::vector<PII> VPII;

typedef std::vector< VC > VC2;
typedef std::vector< VI > VI2;
typedef std::vector< VL > VL2;
typedef std::vector< VLL > VLL2;

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

std::string S, T;
int lenS, lenT;
RollingHash rhS, rhT;

bool isOk(const int L, const int R) {
    int l1, r1, l2, r2;
    //left-side
    int left = 0, right = lenT - 1;
    while(right-left > 1) {
        int mid = (left + right) / 2;
        auto hashS = rhS.get_hash_pair(L, L+mid+1);
        auto hashT = rhT.get_hash_pair(0, mid+1);
        if(hashS == hashT) {
            left = mid;
        } else {
            right = mid;
        }
    }
    l1 = left, r1 = right;

    //right-side
    left = 0, right = lenT - 1;
    while(right - left > 1) {
        int mid = (left + right) / 2;
        auto hashS = rhS.get_hash_pair(L + mid, L + lenT);
        auto hashT = rhT.get_hash_pair(mid, lenT);
        if(hashS == hashT) {
            right = mid;
        } else {
            left = mid;
        }
    }

    l2 = left, r2 = right;
    if(S[L+l1] != T[l1]) {
        --l1;
    }
    if(S[L+r2] != T[r2]) {
        ++r2;
    }
    return (l1 + 2) == r2;
}


int main() {
    std::cin >> S;
    std::cin >> T;

    lenS = S.length(), lenT = T.length();
    if(S == T) {
        std::cout << 0 << std::endl;
        return 0;
    } else if(lenT == 1) {
        int cnt = 0;
        for(auto c: S) {
            if(c != T[0]) {
                ++cnt;
            }
        }
        std::cout << cnt << std::endl;
        return 0;
    }

    rhS = RollingHash(), rhT = RollingHash();
    rhS.init(S);
    rhT.init(T);
    int ans = 0;
    REP(i, lenS-lenT+1) {
        if(isOk(i, i+lenT-1)) {
            ans += 1;
        }
    }
   std::cout << ans << std::endl;
   return 0;
}