#include <iostream>
#include <vector>
#include <deque>
#include <utility>

int R, C;
int sy, sx;
int gy, gx;

std::vector< std::vector<char> > map;
std::vector< std::vector<int> > dis;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void){
    std::deque< std::pair<int,int> > deq;

    std::cin >> R >> C;
    std::cin >> sy >> sx;
    std::cin >> gy >> gx;
    --sy, --sx;
    --gy, --gx;

    map.resize(R, std::vector<char>(C, 0));
    dis.resize(R, std::vector<int>(C, -1));

    int i, j;
    for(i=0; i<R; ++i){
        for(j=0; j<C; ++j){
            std::cin >> map[i][j];
        }
    }

    std::pair<int,int> p;
    p.first  = sy;
    p.second = sx;

    deq.push_back(p);
    dis[sy][sx] = 0;

    int d = 0;
    while(!deq.empty()){
        p = deq.front();
        deq.pop_front();

        if(p.first == gy && p.second == gx) break;

        d = dis[p.first][p.second];

        for(i=0; i<4; ++i){
            int ny = p.first  + dy[i];
            int nx = p.second + dx[i];

            if( ny>=0 && nx>=0 && ny<R && nx<C && map[ny][nx] == '.' && dis[ny][nx] == -1){
                dis[ny][nx] = d + 1;
                deq.push_back(std::make_pair(ny,nx));
            }
        }
    }
    std::cout << dis[gy][gx] << std::endl;
}
