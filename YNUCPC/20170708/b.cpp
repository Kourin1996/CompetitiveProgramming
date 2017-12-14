#include <iostream>
#include <vector>

int C, N;
std::vector< std::vector< char > > p;
std::vector< std::vector< bool > > m;

int total;

bool check(int i, int j){
    return (p[i][j] ==p[N-1-i][j] && p[i][j] == p[i][N-1-j]);
}

void update(int i, int j){
    total -= m[i][j];
    m[i][j] = check(i, j);
    total += m[i][j];
}

void reverse(int i, int j){
    p[i][j] = (p[i][j] == '0' ? '1' : '0');
    update(i, j);
    update(N-1-i, j);
    update(i, N-1-j);
}

int main(void){
    int i, j;

    std::cin >> C >> N;
    p.resize(N, std::vector<char>(N));
    m.resize(N, std::vector<bool>(N));
    for(i=0; i<N; ++i){
        for(j=0; j<N; ++j){
            std::cin >> p[i][j];
        }
    }

    total = 0;
    for(i=0; i<N; ++i){
        for(j=0; j<N; ++j){
            m[i][j] = check(i,j);
            total += m[i][j];
        }
    }

    int ans = (total==N*N ? 1 : 0);
    for(int i=0; i<C-1; ++i){
        int D;
        std::cin >> D;
        for(j=0; j<D; ++j){
            int r, c;
            std::cin >> r >> c;
            reverse(r-1, c-1);
        }
        ans += (total==N*N ? 1 : 0);
    }
    std::cout << ans << std::endl;
}
