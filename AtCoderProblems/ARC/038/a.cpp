#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> A;

int main(void){
    std::cin >> N;
    A.resize(N);

    for(int i=0; i<N; ++i){
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), std::greater<int>());

    int ans = 0;
    for(int i=0; i<N; ++i){
        if(i%2 == 0){
            ans += A[i];
        }
    }
    std::cout << ans << std::endl;
}
