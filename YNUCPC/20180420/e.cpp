#include <bits/stdc++.h>

const int MOD = 1e9+7;
int n;
std::vector<int> a, b;

int main() {
    int i;
    std::cin >> n;
    a.resize(n), b.resize(n);
    for(i=0 ;i<n; ++i) {
        std::cin >> a[i];
    }
    for(i=0 ;i<n; ++i) {
        std::cin >> b[i];
    }

    std::vector< std::pair<int,bool> > x;
    for(i = 0; i < n; ++i) {
        x.push_back({a[i], false});
        x.push_back({b[i], true});
    }
    std::sort(x.begin(), x.end());

    long long int result = 1;
    int cnt = 0;
    for (auto y : x) {
        int delta = (y.second ? 1 : -1);
        if (cnt != 0 && (cnt > 0) != y.second) {
            result = (result * std::abs(cnt)) % MOD;
        }
        cnt += delta;
    }
    std::cout << result << std::endl;
}
 