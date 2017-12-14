#include <iostream>
int N = 0;
int a = 0, b = 0;
int main(void){
    int ans = 0;;

    std::cin >> N;
    for(int i=0; i<N; ++i){
        std::cin >> a >> b;
        ans += a*b;
    }
    ans = 1.05*ans;

    std::cout << ans << std::endl;
}
