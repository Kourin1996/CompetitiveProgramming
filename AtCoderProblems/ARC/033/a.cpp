#include <iostream>
int N = 0;
int main(void){
    std::cin >> N;
    long long int ans = 0;
    for(int i=0; i<N; ++i){
        ans += (N-i);
    }
    std::cout << ans << std::endl;
}
