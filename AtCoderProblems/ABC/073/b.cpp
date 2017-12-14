#include <iostream>
int N;
int main(void){
    std::cin >> N;
    long l, r;
    long ans = 0;
    for(int i=0; i<N; ++i){
        std::cin >> l >> r;
        ans += r-l+1;
    }
    std::cout << ans << std::endl;
}
