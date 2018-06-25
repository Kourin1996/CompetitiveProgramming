#include<bits/stdc++.h>

#define REP(i,a) for(long i=0;i<(a);++i)

typedef std::vector<int>  VI;

int N;
VI a, b, x;
int main() {
    std::cin >> N;
    a.resize(N), b.resize(N);
    x.resize(N+2);

    REP(i, N) {
        std::cin >> a[i] >> b[i];
        
        for(int j=a[i]; j<=b[i]; ++j) {
            ++x[j];
        }
    }

    int ans = 0;
    for(int i=0; i<=N+1; ++i) {
        if(x[i] + 1 >= i) {
            ans = i - 1;
        }
    }
    
    std::cout << ans << std::endl;
}