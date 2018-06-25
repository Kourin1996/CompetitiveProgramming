#include <bits/stdc++.h>

struct SCORE {
    int id, ans, elapsed;
    std::vector<int> miss;
    SCORE() {
        id = 0;
        ans = 0;
        elapsed = 0;
        miss.resize(10);
    }
    bool operator > (const SCORE &y) const {
        if(ans > y.ans) return true;
        if(ans < y.ans) return false;
        if(elapsed < y.elapsed) return true;
        if(elapsed > y.elapsed) return false;
        return id > y.id;
    }

    bool operator == (const SCORE &y) const {
        return (ans == y.ans) && (elapsed == y.elapsed);
    }
};

int main() {
    int M, T, P, R;
    int m, t, p, j;
    int i;

    std::vector< SCORE > player(50);
    while(std::cin >> M >> T >> P >> R) {
        if(M == 0 && T == 0 && P == 0 && R == 0) break;
        
        for(i = 0; i < T; ++i) {
            player[i].id = i + 1;
            player[i].ans = 0;
            player[i].elapsed = 0;
            for(j = 0; j < 10; ++j) {
                (player[i]).miss[j] = 0;
            }
        }
        for(i = 0; i < R; ++i) {
            std::cin >> m >> t >> p >> j;
            if(j == 0) {
                player[t - 1].ans += 1;
                player[t - 1].elapsed += (m + 20*(player[t-1]).miss[p - 1]);
            } else {
                ++(player[t - 1]).miss[p - 1];
            }
        }
        std::sort(player.begin(), player.begin() + T, std::greater<SCORE>());

        SCORE old;
        for(int i=0; i<T; ++i) {
            if(i == 0) {
                std::cout << player[i].id;
                old = player[i];
                continue;
            }

            if(old == player[i]) {
                std::cout << "=" << player[i].id;
            } else {
                std::cout << "," << player[i].id;
            }
            old = player[i];
        }
        std::cout << std::endl;
    }

}