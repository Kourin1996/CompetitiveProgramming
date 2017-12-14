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

VI2 g;
std::vector<bool> visited;
std::vector<int> matching;

bool augment(int l) {
    if(l < 0) return true;
    if(visited[l]) return false;
    visited[l] = true;
    REP(i, g[l].size()) {
        int r = g[l][i];
        if(augment(matching[r])) {
            matching[r] = l;
            return true;
        }
    }
    return false;
}

const int di[] = {0,-1,0,1};
const int dj[] = {1,0,-1,0};

int main() {
    int n, m;
    VC2 table;
    int cnt = 0;
    while(std::cin >> n >> m, n != 0 && m != 0) {
        table.resize(n, VC(m));
        int dots = 0;
        REP(i, n) REP(j, m) {
            std::cin >> table[i][j];
            if(table[i][j] == '.') ++dots;
        }
        g.resize((n*m)/2 + (n*m)%2);

        REP(i, n) REP(j, m) {
            if(table[i][j] == '#') continue;
            if(i+j == 0 || (i+j) % 2 == 0) {
                int l = i*(m/2) + j/2;
                REP(k, 4) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni >= 0 && nj >= 0 && ni < n && nj < m && table[ni][nj] != '#') {
                        g[l].pb( ni*(m/2) + nj/2 );
                    }
                }
            }
        }

        matching.assign((n*m)/2 + (n*m)%2, -1);
        int matches = 0;
        REP(i, (n*m)/2) {
            visited.assign((n*m)/2 + (n*m)%2, false);
            if(augment(i)) {
                matches++;
            }
        }
        int r = dots - matches * 2;
        std::cout << "Case #" << ++cnt << ": " << r / 2 + r % 2 << std::endl;
    }
}