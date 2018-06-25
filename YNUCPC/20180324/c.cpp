
#include<bits/stdc++.h>

#define FOR(i,a,b) for(auto i=(a);i<(b);++i)
#define REP(i,a) for(long i=0;i<(a);++i)

typedef std::vector<char> VC;
typedef std::vector< VC > VC2;

const int MAX_T = 1260;
const int MAX_M = 10000;

int N, M;
VC2 login(MAX_T+2, VC(MAX_M, 0));

void solve() {
    int a = MAX_T+2, b = MAX_M;
    REP(i, a) REP(j, b) login[i][j] = 0;

    int r, q;
    //log
    std::cin >> r;
    REP(i, r) {
        int t, n, m, s;
        std::cin >> t >> n >> m >> s;
        --m;
        if(login[m][t] == 0) {
            login[m][t] = (s == 1 ? 1 : -1);
        } else {
            login[m][t] = ((s == 1 || login[m][t] == 1) ? 1 : -1);
        }
    }
    REP(m, M) {
        REP(t, MAX_T+1) {
            login[m][t+1] += login[m][t];
        }
    }

    //question
    std::cin >> q;
    REP(i, q) {
        int s, e, m;
        std::cin >> s >> e >> m;

        int sum = 0;
        FOR(i, s, e+1) {
            sum += (login[m][i] > 0);
        }
        std::cout << sum << std::endl;
    }
}

int main() {
    while(std::cin >> N >> M, !(N == 0 && M == 0)) {
        solve();
    }  
}