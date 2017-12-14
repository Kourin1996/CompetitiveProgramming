#include<bits/stdc++.h>
#define REP(i,a) for(long i=0;i<(a);++i)

int H, W;
int main() {
    std::cin >> H >> W;
    int cnt = 0;

    char c;
    REP(i, H) {
        REP(j, W) {
            std::cin >> c;
            cnt += (int)(c == '#');
        }
    }

    std::cout << (((H+W-1) == cnt) ? "Possible" : "Impossible") << std::endl; 
}