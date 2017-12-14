#include <iostream>
#include <vector>
#include <algorithm>
int N;
int K;

int main(void){
    std::cin >> N;
    std::cin >> K;
    int x;
    int ans = 0;
    for(int i=0; i<N; ++i){
        std::cin >> x;
        ans += 2*std::min(x, K-x);
    }
    std::cout << ans << std::endl;
}
