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
typedef std::vector<char> VC;
typedef std::vector< VC > VCC;
typedef std::vector<int>  VI;
typedef std::vector< VI > VII;
typedef std::vector<long> VL;
typedef std::vector<long long> VLL;
typedef std::pair<int,int> PII;

int H, W;
VCC table;
VII ans;
int dx[] = {-1,0,1,1,1,0,-1,-1};
int dy[] = {-1,-1,-1,0,1,1,1,0};
int main() {
    std::cin >> H >> W;
    table.resize(H, VC(W));
    ans.resize(H, VI(W, 0));

    REP(i, H) {
        REP(j, W) {
            std::cin >> table[i][j];
            if(table[i][j] == '#') {
                REP(k, 8) {
                    int x = j + dx[k];
                    int y = i + dy[k];
                    if(x >= 0 && y >= 0 && x < W && y < H) {
                        ans[y][x]++;
                    }
                }
            }
        }
    }

    REP(i, H) {
        REP(j, W) {
            if(table[i][j] == '#') {
                std::cout << "#";
            } else {
                std::cout << ans[i][j];
            }
        }
        std::cout << "\n";
    }
}