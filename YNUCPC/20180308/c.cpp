#include<bits/stdc++.h>

#define REP(i,a) for(long i=0;i<(a);++i)
typedef long long int LL;
typedef std::vector<LL> VLL;

int N;
VLL A;

int main() {
    std::cin >> N;
    A.resize(N);
    REP(i, N) {
        std::cin >> A[i];
    }

    LL ans1 = 0, ans2 = 0;

    LL sum = 0, dist = -1;
    REP(i, N) {
        dist *= -1;
        sum += A[i];
        if(sum * dist <= 0) {
            ans1 += std::abs(sum - dist);
            sum = dist;
        }
    }

	sum = 0, dist = 1;
    REP(i, N) {
        dist *= -1;
        sum += A[i];
        if(sum * dist <= 0) {
            ans2 += std::abs(sum - dist);
            sum = dist;
        }
    }
    std::cout << std::min(ans1, ans2) << std::endl;
}