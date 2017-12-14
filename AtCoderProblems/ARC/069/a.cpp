#include <iostream>

long N, M;
int main() {
    std::cin >> N >> M;

    long ans = std::min(N, M/2);
    M -= ans * 2;
    ans += M/4;

    std::cout << ans << std::endl;
}