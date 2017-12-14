#include<bits/stdc++.h>

#define REP(i,a) for(long i=0;i<(a);++i)
#define SORT(a) std::sort((a).begin(), (a).end())

//alias
typedef std::vector<int>  VI;

int N;
VI L;
int main() {
    std::cin >> N;
    L.resize(N*2);
    REP(i, N*2) {
        std::cin >> L[i];
    }

    SORT(L);

    int sum = 0;
    REP(i, N) {
        sum += L[i*2];
    }
    std::cout << sum << std::endl;
}