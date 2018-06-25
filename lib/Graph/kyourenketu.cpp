#include <bits/stdc++.h>

//common
typedef long long Weight;
const Weight WEIGHT_INF = std::numeric_limits<Weight>::max() / 4;

struct Edge {
    int src, dst;
    Weight weight;
};
bool operator<(const Edge &a, const Edge &b) {
    return (a.weight < b.weight);
};
bool operator>(const Edge &a, const Edge &b) {
    return (a.weight > b.weight);
};
typedef std::vector<Edge> Edges;
typedef std::vector<Edges> Graph;

void visit(const Graph &g, int v, std::vector<std::vector<int>> &scc, std::stack<int> &S, std::vector<bool> &inS, std::vector<int> &low, std::vector<int> &num, int &time) {
    low[v] = num[v] = ++time;
    S.push(v);
    inS[v] = true;
    for(auto e : g[v]){
        int w = e.dst;
        if(num[w] == 0) {
            visit(g, w, scc, S, inS, low, num, time);
            low[v] = std::min(low[v], low[w]);
        }
        else if(inS[w]) {
            low[v] = std::min(low[v], low[w]);
        }
    }
    if(low[v] == num[v]) {
        scc.push_back(std::vector<int>());
        while(1){
            int w = S.top();
            S.pop();
            inS[w] = false;
            scc.back().push_back(w);
            if(v == w) break;
        }
    }
}

void stronglyConnectedComponents(const Graph &g, std::vector<std::vector<int>> &scc) {
    const int n = g.size();
    std::vector<int> num(n), low(n);
    std::stack<int> S;
    std::vector<bool> inS(n);
    int time = 0;
    for (int u = 0; u < n; ++u) {
        if (num[u] == 0) {
            visit(g, u, scc, S, inS, low, num, time);
        }
    }
}

int main() {
    Graph g(10);
    g[0].push_back(Edge{0, 1, 1});
    g[1].push_back(Edge{1, 2, 1});
    g[1].push_back(Edge{1, 3, 1});
    g[2].push_back(Edge{2, 3, 1});
    g[2].push_back(Edge{2, 5, 1});
    g[2].push_back(Edge{2, 6, 1});
    g[3].push_back(Edge{3, 4, 1});
    g[3].push_back(Edge{3, 7, 1});
    g[4].push_back(Edge{4, 1, 1});
    g[5].push_back(Edge{5, 8, 1});
    g[6].push_back(Edge{6, 7, 1});
    g[7].push_back(Edge{7, 8, 1});
    g[8].push_back(Edge{8, 6, 1});
    g[8].push_back(Edge{8, 9, 1});

    std::vector<std::vector<int>> scc;
    stronglyConnectedComponents(g, scc);

    std::cout << "result\n";
    int i = 0;
    for(auto sc: scc) {
        std::cout << i++ << ": ";
        if(!sc.empty()) for(auto s: sc) {
            std::cout << s << " ";
        }
        std::cout << "\n";
    }
}