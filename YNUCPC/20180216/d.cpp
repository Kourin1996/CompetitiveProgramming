#include <bits/stdc++.h>
#define REP(i,a) for(long i=0;i<(a);++i)
#define RREP(i,a) for(long i=(a);i>=0;--i)
#define SORT(a) std::sort((a).begin(), (a).end())
typedef std::vector<long> VL;

int N, K;
VL a;

int main() {
    std::cin >> N >> K;
    a.resize(N);
    REP(i, N) std::cin >> a[i];

    SORT(a);

    int sum = 0;
    int ans = N;
    RREP(i, N-1) {
        if(sum + a[i] < K) {
            sum += a[i];
        } else {
            ans = i;
        }
    }
    std::cout << ans << std::endl;
}
