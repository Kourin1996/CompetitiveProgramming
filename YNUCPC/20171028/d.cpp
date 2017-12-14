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
typedef std::vector< PII > VP;

int n;
int min = 1e9;
VP g;
VP ans;

int gcd(int a, int b) {
    int min = std::min(a,b);
    int max = std::max(a,b);

    if(min == 0) return max;
    else         return gcd(min, max%min);
}

void dfs(int i, int p, int sum) {
    if(p + (n-i) >= 40) return; 
    if(i >= n) {
        if(min > sum) {
            min = sum;
            REP(j, n) {
                ans[j] = g[j];
            }
        }
        return;
    }
    const int x = g[i].fst;

    //1にする
    if(x != 1) {
        g[i].fst = 1;
        dfs(i+1, std::max(1, p), sum + x - 1);
    }

    //
    for(int j=p+1; j<=39; ++j) {
        bool f = true;
        for(int k=0; k<i; ++k) {
            if(gcd(j,g[k].fst) != 1) {
                f = false;
                break;
            }
        }
        if(f) {
            g[i].fst = j;
            dfs(i+1, j, sum + std::abs(x-j));
        }
    }
    g[i].fst = x;
}

int main() {
    int cnt = 0;
    while(std::cin >> n, n != 0) {
        g.resize(n);
        ans.resize(n);

        REP(i, n) {
            std::cin >> g[i].fst;
            g[i].snd = i;
        }

        std::sort(g.begin(), g.end(), [](const PII& a, const PII& b){return (a.fst != b.fst) ? (a.fst < b.fst) : (a.snd < b.snd);});
        dfs(0, 0, 0);
        std::sort(ans.begin(), ans.end(), [](const PII& a, const PII& b){return a.snd < b.snd;});

        std::cout << "Case #" << ++cnt << ":";
        REP(i, n) {
            std::cout << " " << ans[i].fst;
        }
        std::cout << std::endl;
    }
    return 0;
}