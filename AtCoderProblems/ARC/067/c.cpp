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

int N;
const int MOD = 1e9 + 7;

std::vector<int> prim;
void getPrim(int N) {
    prim.reserve(N/2);
    std::vector<bool> used(N+1, false);
    REP(i, 4) {
        used[i] = true;
    }
    prim.pb(2);
    prim.pb(3);
    FOR(i, 1, (N+1)/2) {
        if(i*2 <= N) used[i*2] = true;
        if(i*3 <= N) used[i*3] = true;
    }

    FOR(i, 1, N/6 + 1) {
        int a = 6*i - 1;
        if(a > N) break;
        if(!used[a]) {
            prim.pb(a);
            FOR(i, 1, (N+a-1)/a){
                used[a*i] = true;
            }
        }

        int b = 6*i + 1;
        if(b > N) break;
        if(!used[b]) {
            prim.pb(b);
            FOR(i, 1, (N+b-1)/b){
                used[b*i] = true;
            }
        }
    }
}

int main() {
    std::cin >> N;
    getPrim(N);

    std::vector<int> cnt(N+1, 0);
    FOR(i, 2, N+1) {
        EACH(j, prim) {
            if(i < (*j)) break;

            int x = i;
            while( x >= (*j) && x%(*j)==0 ) {
                cnt[*j]++;
                x /= *j;
            }
        }
    }
    LL ans = 1ll;
    EACH(it, cnt) {
        if(*it > 0) {
            ans =  ( ( ans + MOD ) * (*it + 1) ) % MOD;
        }
    }
    std::cout << ans << std::endl;
}