#include <iostream>

int N, M;

int main(void){
    int i, j, k, n, m;
    std::cin >> N >> M;

    for(i=0; i<=N; ++i){
        n = N - i;
        m = M - 2*i;

        k = m-3*n;
        j = n - k;
        if( (j<0) || (k<0) ) continue;
        if(i+j+k != N) continue;

        std::cout << i << " " << j << " " << k << std::endl;
        return 0;
    }
    std::cout << -1 << " " << -1 << " " << -1 << std::endl;
}
