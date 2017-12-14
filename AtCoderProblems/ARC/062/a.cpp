#include <bits/stdc++.h>

int N;
int main() {
    std::cin >> N;
    long long T, A;
    long long x = 1, y = 1;
    for(long long i=0; i<N; i++){
        std::cin >> T >> A;
        long long n = std::max( x/T+(x%T != 0), y/A+(y%A!=0));
        x = n*T;
        y = n*A;
    }
    std::cout << x+y << std::endl;
}
