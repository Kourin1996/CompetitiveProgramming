#include <bits/stdc++.h>

int N, Y;
int main() {
    std::cin >> N >> Y;
    for(int i=0; i<=N; ++i) {
        for(int j=0; i+j<=N; ++j) {
            int k = std::max(0, N-i-j);
            if((i+j+k) == N && (10000*i + 5000*j + 1000*k) == Y) {
                std::cout << i << " " << j << " " << k << std::endl;
                return 0;
            }
        }
    }
    std::cout << "-1 -1 -1" << std::endl;
    return 0;
}