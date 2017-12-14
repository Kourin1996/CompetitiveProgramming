#include<bits/stdc++.h>

#define REP(i,a) for(long i=0;i<(a);++i)
typedef std::vector<int>  VI;
typedef std::vector< VI > VI2;

VI2 g;
void warshallFloyd() {
    int n = g.size();
    REP(k, n) REP(i, n) REP(j, n) {
        g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
    }
}

int N, M;
int main() {
    std::cin >> N >> M;
    g.resize(N, VI(N, 100));
    int A, B;
    REP(i, M) {
        std::cin >> A >> B;
        A--, B--;
        g[A][B] = g[B][A] = 1;
    }
    warshallFloyd();

    REP(i, N) {
        int cnt = 0;
        REP(j, N) {
            cnt += (int)(i != j && g[i][j] == 2);
        }
        std::cout << cnt << std::endl;
    }
}