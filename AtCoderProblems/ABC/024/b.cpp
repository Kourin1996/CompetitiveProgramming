#include <iostream>
#include <algorithm>
int N = 0, T = 0;
int A = 0;

int main(void){
    std::cin >> N >> T;
    int right = 0;
    int ans = 0;
    for(int i=0; i<N; ++i){
        std::cin >> A;
        ans += std::min(T, A+T-right);
        right = A + T;
    }
    std::cout << ans << std::endl;
}
