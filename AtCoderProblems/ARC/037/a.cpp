#include <iostream>

int N = 0;

int main(void){
    std::cin >> N;

    int m = 0;

    int ans = 0;
    for(int i=0; i<N; ++i){
        std::cin >> m;
        ans += (m>=80) ? 0 : 80-m;
    }
    std::cout << ans << std::endl;
}
