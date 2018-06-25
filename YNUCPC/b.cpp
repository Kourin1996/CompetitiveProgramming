#include <bits/stdc++.h>

int N;
std::vector<int> a;
int main() {
    std::cin >> N;
    a.resize(N);
    for(int i=0; i<N; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    std::cout << std::abs(a[0] - a[N-1]) << std::endl;
}