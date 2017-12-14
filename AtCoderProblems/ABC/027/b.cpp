#include <iostream>
#include <vector>
#include <cstdlib>
int N = 0;
std::vector<int> a;
int main(void){
    std::cin >> N;
    a.resize(N);

    int sum = 0;
    for(int i=0; i<N; ++i){
        std::cin >> a[i];
        sum += a[i];
    }

    if(sum % N > 0){
        std::cout << -1 << std::endl;
    }else{
        int ans = 0;

        int req = sum / N;
        int rem = 0;
        for(int i=0; i<N; ++i){
            rem += a[i]-req;
            ans += !!rem;
        }
        std::cout << ans << std::endl;
    }
}

