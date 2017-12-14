#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

int m, n;
int w[100];

std::vector< std::vector<int> > memo(21, std::vector<int>(101));

const int MAX_WIDTH = 1500000;

int dfs(int i, int j){
    if(memo[i][j] != -1){
        return memo[i][j];
    }

    if(i >= m){
        return memo[i][j] = ( (j<n) ? -1 : 0 );
    }
    if(j >= n){
        return memo[i][j] = 0;
    }

    int ans = INT_MAX;

    int width = 0;
    int res;
    for(int k=j; k<n; ++k){
        width += w[k];

        res = dfs(i+1, k+1);
        if(res >= 0){
            ans = std::min(ans, std::max(width,res));
        }
    }

    return memo[i][j] = ans;
}

int main(void){
    while(std::cin >> m >> n){
        if(m == 0 && n == 0) break;
        for(int i=0; i<n; ++i){
            std::cin >> w[i];
        }

        for(int i=0; i<=m; ++i){
            for(int j=0; j<=n; ++j){
                memo[i][j] = -1;
            }
        }
        std::cout << dfs(0,0) << std::endl;
    }
}
