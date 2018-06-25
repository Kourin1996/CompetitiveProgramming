#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int N, M;
long long int fact(int n) {
    long long int x = 1;
    for(int i=2; i<=n; ++i) {
        x *= i;
        x %= MOD;
    }
    return x;
}
int main() {
    std::cin >> N >> M;

    int diff = std::abs(N - M);
    if(diff >= 2) {
        std::cout << 0 << std::endl;
        return 0;
    } 

    long long int ans = (fact(N) * fact(M)) % MOD;
    if(diff == 1) {
        std::cout << (int)ans << std::endl;
    } else if(diff == 0) {
        ans *= 2;
        ans %= MOD;
        std::cout << (int)ans << std::endl;
    }
}