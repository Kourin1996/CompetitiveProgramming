#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>

int N, K;
std::vector< int > R;

int main(void){
    std::cin >> N >> K;
    R.resize(N);
    for(int i=0; i<N; ++i) std::cin >> R[i];

    std::sort(R.begin(), R.end(), std::greater<int>());

    double rate = 0.0;
    for(int i=K-1; i>=0; --i){
        rate = (rate + R[i])/2.0;
    }
    std::cout << std::fixed << std::setprecision(7) << rate << std::endl;
}
