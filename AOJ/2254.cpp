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
VL2 t;
VL memo;

const long inf = std::numeric_limits<long>::max();

int main() {
    t.resize(16, VL(17));
    memo.resize(1<<16);

    while(std::cin >> N, N != 0) {
        memo.assign(1 << N, inf);

        REP(i, N) {
            REP(j, N+1) {
                std::cin >> t[i][j];
            }
        }

        memo[0] = 0;
        REP(bit, 1 << N) {
            REP(j, N) {
                if( !((bit >> j) & 0x01)) {
                    long min = t[j][0];
                    REP(k, N) {
                        if( (bit >> k) & 0x01 ) {
                            min = std::min(min, t[j][k+1]);
                        }
                    }
                    int mask = bit | (1 << j);
                    memo[mask] = std::min(memo[mask], memo[bit] + min);
                }
            }
        }
        std::cout << memo[(1<<N)-1] << std::endl;
    }
}