#include <iostream>
#include <algorithm>
#include <vector>

int N, K;
std::vector<long long int> s;

int main() {
    std::cin >> N >> K;
    bool f = false;
    s.resize(N);
    for (int i = 0; i < N; i++) {
        std::cin >> s[i];
        if (s[i] == 0){
            f = true;
        }
    }

    if(f){
        std::cout << N << std::endl;
    } else {
        int l = 0, r = 0, ans = 0;
        long long tmp = 1;
        while (l <= r && r < N) {
            while (r < l && r < N) tmp /= s[r++];
            while (tmp * s[r] <= K && r < N) tmp *= s[r++];
            ans = std::max(ans, r - l);
            tmp /= s[l++];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
