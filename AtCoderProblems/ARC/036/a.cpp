#include <iostream>
#include <vector>
#include <numeric>

int N = 0, K = 0;
std::vector<int> t;

int main(void){
    std::cin >> N >> K;
    t.resize(N, 0);

    int ans = -1;
    for(int i=0; i<N; ++i){
        std::cin >> t[i];
        if(i < 2) continue;
        if((t[i-2]+t[i-1]+t[i]) < K){
            ans = i+1;
            break;
        }
    }
    std::cout << ans << std::endl;
}
