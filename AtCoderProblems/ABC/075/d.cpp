#include <bits/stdc++.h>

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
#define UNIQUE(a) SORT(a), a.erase(std::unique(ALL(a)), a.end());

//Setting
#define OPT std::cin.tie(0);std::ios::sync_with_stdio(false);

//debug message
bool debug = true;
#define MSG(s)   if(debug){std::cout << s << std::endl;}
#define DEBUG(x) if(debug){std::cout << "debug(" << #x << "): " << x << std::endl;}

//alias
typedef long long LL;
typedef std::vector<char> VC;
typedef std::vector< VC > VCC;
typedef std::vector<int>  VI;
typedef std::vector< VI > VII;
typedef std::vector<long> VL;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;
typedef std::pair<int,int> PII;

int N, K;
std::vector< PII > coord;
VI X;
VI Y;

inline int cont(int xl, int xr, int yd, int yu) {
    int ans = 0;
    EACH(it, coord) {
        if(it->fst >= xl && it->fst <= xr && it->snd >= yd && it->snd <= yu) {
            ans++;
        }
    }
    return ans;
}


int main() {
    std::cin >> N >> K;
    coord.resize(N);
    X.resize(N);
    Y.resize(N);
    
    int x, y;
    REP(i, N) {
        std::cin >> x >> y;
        coord[i].fst = x;
        coord[i].snd = y;
        X[i] = x;
        Y[i] = y;
    }
    SORT(X);
    SORT(Y);

    LL ans = LLONG_MAX;
    EACH(xl, X) EACH(xr, X) {
        if(*xl >= *xr) continue;

        EACH(yd, Y) EACH(yu, Y) {
            if(*yd >= *yu) continue;

            int a = cont(*xl,*xr,*yd,*yu);
            if(a >= K) {
                LL s = std::abs((LL)*xr-(LL)*xl)*std::abs((LL)*yu-(LL)*yd);
                ans = std::min(ans, s);
            }
        }
    }
    std::cout << ans << std::endl;
}