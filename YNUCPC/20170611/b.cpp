#include <iostream>
#include <algorithm>
int M, N;
int main(void){
    int i, j, a, x;
    int max = 0;
    std::cin >> M >> N;
    for(i=0; i<M; ++i){
        x = 0;
        for(j=0; j<N; ++j){
            std::cin >> a;
            x += a;
        }
        max = std::max(max,x);
    }
    std::cout << max << std::endl;
}
