#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int degree[100];

int n, m;
std::vector<std::pair<int,int> > ab(500);
std::vector<int>                  c(500);

int dfs(int i){
    if(i >= m){
        return 0;
    }

    int from = ab[i].first;
    int to   = ab[i].second;

    int res1 = dfs(i+1);
    int res2 = 0;
    if(degree[from] > 1 && degree[to] > 1){
        --degree[from];
        --degree[to];
        res2 = dfs(i+1) + c[i];
        ++degree[from];
        ++degree[to];
    }

    return std::max(res1, res2);
}

int main(void){

    while(std::cin >> n >> m){
        if(n == 0 && m == 0) break;
        for(int i=0; i<n; ++i){
            degree[i] = 0;
        }

        int sum = 0;
        for(int i=0; i<m; ++i){
            std::cin >> ab[i].first >> ab[i].second >> c[i];
            ++degree[ab[i].first];
            ++degree[ab[i].second];

            sum += c[i];
        }

        int res = dfs(0);
        std::cout << sum-res << std::endl;
    }
}
