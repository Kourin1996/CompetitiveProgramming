#include <iostream>
int m = 0, n = 0, N = 0;
int main(void){
    std::cin >> m >> n >> N;

    int ans = 0;
    int res = 0;
    while(N > 0){
        ans += N;
        res += N;

        N = (res/m)*n;
        res = res % m;
    }

    std::cout << ans << std::endl;
}
