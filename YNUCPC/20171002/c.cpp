#include <iostream>
#include <cmath>

int N;
int A;
int main(void){
    long long int ans = 0;
    std::cin >> N;
    for(int i=0; i<N; ++i){
        std::cin >> A;
        ans += A*std::pow(2, N-1-i);
    }
    std::cout << ans << std::endl;
}
