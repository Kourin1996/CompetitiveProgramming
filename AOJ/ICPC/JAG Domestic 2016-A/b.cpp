#include <bits/stdc++.h>

int N, M, T;
std::vector<int> t(1e5, 1);
int main() {
    std::cin >> N >> M >> T;

    int a;
    for(int i = 0; i<N; ++i) {
        std::cin >> a;
        for(int j = a - M; j < a + M; ++j) {
            t[j] = 0;
        }
    }
    int ans = std::accumulate(t.begin(), t.begin() + T, 0);
    std::cout << ans << std::endl;
}