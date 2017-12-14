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

int H, W;
VI2 C(10, VI(10));
VI2 A;

void warshallFloyd() {
    int n = C.size();
    REP(k, n) REP(i, n) REP(j, n) {
        REP(k, n) REP(i, n) REP(j, n) {
            C[i][j] = std::min(C[i][j], C[i][k] + C[k][j]);
        }
    }
}

int main() {
    std::cin >> H >> W;
    A.resize(H, VI(W));
    REP(i, 10) {
        REP(j, 10) {
            std::cin >> C[i][j];
        }
    }

    warshallFloyd();

    long ans = 0L;
    REP(i, H) {
        REP(j, W) {
            int A;
            std::cin >> A;
            if(A == -1 || A == 1) continue;
            ans += C[A][1];
        }
    }
    std::cout << ans << std::endl;


}