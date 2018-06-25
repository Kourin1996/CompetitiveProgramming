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

const LL MOD = 1000000007;
int N;
std::string S1, S2;
int main() {
    std::cin >> N;
    std::cin >> S1;
    std::cin >> S2;

    LL ans = 1;
    int x = 0;
    int prev = -1;
    while(x < N) {
        if (S1[x] == S2[x]) {
            if (prev == -1) {
                ans = 3;
            }
            else if(prev == 0) {
                ans *= 2;
            }
            else {
                ans *= 1;
            }
            x++;
            prev = 0;
        } else {
            if(prev == -1) {
                ans = 6;
            } else if(prev == 0) {
                ans *= 2;
            } else {
                ans *= 3;
            }
            x += 2;
            prev = 1;
        }
        ans %= MOD;
    }
    std::cout << ans << std::endl;
}