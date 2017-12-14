#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
#include <queue>

struct edge{
    int v;
    long long int w;
    edge(){};
    edge(const int& v, const long long int& w):v(v), w(w){};
};

std::vector<int> A;

std::vector<long long int> dijkstra(const int& n, const std::vector< std::vector< edge > >& G, const int &s){
    std::vector<long long int> d(n, LLONG_MAX/10); d[s] = 0;

    std::priority_queue<std::pair<long long int, int> > que;
    que.push(std::make_pair(0ll, s));

    while(!que.empty()){
        auto p = que.top(); que.pop();
        int  u = p.second;

        long long int dist = -p.first;
        if(dist > d[u]) continue;
        for(edge e: G[u]){
            if(d[e.v] > d[u] + e.w){
                d[e.v] = d[u] + e.w;
                que.push(std::make_pair(-d[e.v], e.v));
            }
        }
    }
    return d;
}

int main(void){
    int N, M, T;
    std::cin >> N >> M >> T;

    A.resize(N);
    for(int i=0; i<N; ++i){
        std::cin >> A[i];
    }

    std::vector< std::vector< edge > > G(N), rG(N);
    for(int i=0; i<M; ++i){
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
         G[a].emplace_back(b,c);
        rG[b].emplace_back(a,c);
    }

    auto  d = dijkstra(N,  G, 0);
    auto rd = dijkstra(N, rG, 0);

    long long int ans = 0;
    for(int i=0; i<N; ++i){
        long long int need = d[i] + rd[i];
        if(need > T) continue;
        ans = std::max(ans, (T-need)*A[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}
