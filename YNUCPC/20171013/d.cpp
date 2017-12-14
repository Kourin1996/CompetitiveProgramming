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

long T;
long R, C, Q;
long a, b, c, d;

std::vector< std::vector<long long> > base(1005, VLL(1005));
void init() {
    REP(i, 1000) {
        REP(j, 1000) {
            if(i == 0 || j == 0) {
                base[i][j] = 1;
            } else {
                base[i][j] = base[i-1][j]%912 + base[i][j-1]%912;
                base[i][j] %= 912;
            }
        }
    }
}

long long solve() {
    long long ans1 = 0, ans2 = 0;
    long long A, B;
    REP(i, a) {
        A = base[d+1][i] - (i==0 ? 0 : base[d+1][i-1]);
        if(C-d-2 < 0 || R-i-1 < 0) {
            B = 0;
        } else {
            B = base[C-d-2][R-i-1];
        }
        ans1 += A*B;
        ans1 %= 912;
    }
    REP(i, b) {
        A = base[i][c+1] - (i==0 ? 0 : base[i-1][c+1]);
        if(C-i-2 < 0 || R-c-2 < 0) {
            B = 0;
        } else {
            B = base[C-i-1][R-c-2];            
        }
        ans2 += A*B;
        ans2 %= 912;
    }
    return std::max(0ll, std::abs(ans1) + std::abs(ans2))%912;
}

int main() {
    std::cin >> T;
    init();
    REP(i, T) {
        std::cout << "Case " << i+1 << std::endl;
        std::cin >> R >> C >> Q;
        REP(j, Q) {
            std::cin >> a >> b >> c >> d;
            std::cout << "   Query " << j+1 << ": " << solve() << std::endl;
        }
    }
}
