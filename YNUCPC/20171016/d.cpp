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

LL H, W, N;
std::set< PII > AB;
std::set< PII > looked;
VLL cnt(10,0);
int main() {
    std::cin >> H >> W >> N;

    REP(i, N) {
        PII p;
        std::cin >> p.snd >> p.fst;
        p.fst--;
        p.snd--;
        AB.insert(p);
    }

    EACH(it, AB) {
        int x = it->fst, y = it->snd;
        FOR(i, -1, 2) {
            FOR(j, -1, 2) {
                int cx = x + i;
                int cy = y + j;
                if(looked.count(std::make_pair(cx,cy)) > 0) {
                    continue;
                }
                if(cx < 1 || cy < 1 || cx >= W-1 || cy >= H-1){
                    continue;
                }

                looked.insert(std::make_pair(cx,cy));
                int ans = 0;
                FOR(dx, -1, 2) {
                    FOR(dy, -1, 2) {
                        int nx = cx + dx;
                        int ny = cy + dy;
                        if(AB.count(std::make_pair(nx,ny)) > 0) {
                            ans++;
                        }
                    }
                }
                cnt[ans]++;
            }
        }
    }

    cnt[0] = (H-2)*(W-2) - std::accumulate(ALL(cnt), 0);
    REP(i, 10) {
        std::cout << cnt[i] << std::endl;
    }
}