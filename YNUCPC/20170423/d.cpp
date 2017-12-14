#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char tile[21][21] = {0};
int W = 0, H = 0;

bool visited[21][21];

int cnt = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void dig(int x, int y){
    if(x < 0 || x >= W || y < 0 || y >= H){
        return;
    }
    if(tile[y][x] == '#' || visited[y][x]){
        return;
    }

    cnt++;
    visited[y][x] = true;

    for(int i=0; i<4; ++i){
        dig(x + dx[i], y + dy[i]);
    }

    return;
}

int main(void){
    cin >> W >> H;

    int start_x = 0, start_y = 0;

    memset(tile, 0, sizeof(tile));

    for(int i=0; i<H; ++i){
        for(int j=0; j<W; ++j){
            cin >> tile[i][j];
            if(tile[i][j] == '@'){
                start_x = j;
                start_y = i;
            }
        }
    }
    memset(visited, false, sizeof(visited));

    cnt = 0;
    dig(start_x, start_y);

    cout << cnt << endl;
}
