#include <iostream>
int N = 0;
const long long int INF = 1000000007;
int main(void){
    std::cin >> N;

    long long int ans = 1;
    for(int i=1; i<=N; ++i) ans = (ans*i)%INF;
    std::cout << ans << std::endl;
}
