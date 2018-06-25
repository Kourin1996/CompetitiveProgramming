#include <bits/stdc++.h>

typedef long long LL;
typedef std::vector<bool> VB;
typedef std::vector<int>  VI;
typedef std::vector<long long> VLL;
typedef std::vector< VI > VI2;

const int upper = 7368793;
int m, n;
VB isPrime(7368793);
int main() {
    int i, j, k;
    while(std::cin >> m >> n, m != 0 && n != 0) {
        isPrime.assign(upper, true);
        k = m;
        for(i = 0; i < n; ++i) {
            while(!isPrime[k]) ++k;
            for(j = 1; k*j < upper; ++j) {
                isPrime[k*j] = false;
            }
        }
        ++k;
        while(!isPrime[k]) ++k;
        std::cout << k << std::endl;
    }
}