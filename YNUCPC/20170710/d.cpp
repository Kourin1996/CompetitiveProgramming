#include <iostream>
#include <vector>

const long INF = 1e9+7;

int H, W;
std::vector< std::vector<long> > a;
//right,up,left,down
char dx[]  = {1, 0, -1, 0};
char dy[]  = {0, -1, 0, 1};

long memo[1000][1000];
long dp(int x, int y){
    if(memo[x][y] != -1) return memo[x][y];

    long ans = 1;
    for(int i=0; i<4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;

        if(a[y][x] < a[ny][nx]){
            ans += dp(nx, ny);
            ans %= INF;
        }
    }

    return memo[x][y] = (ans%INF);
}

int main(void){
    std::cin >> H >> W;
    a.resize(H, std::vector<long>(W));
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            std::cin >> a[i][j];
            memo[j][i] = -1;
        }
    }

    long ans = 0;
    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            ans += dp(j, i);
            ans %= INF;
        }
    }

    std::cout << ans << std::endl;
}
