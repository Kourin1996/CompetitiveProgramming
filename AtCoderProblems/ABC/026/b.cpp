#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
int N = 0;
std::vector<int> R;
int main(void){
    std::cin >> N;
    R.resize(N);
    for(int i=0; i<N; ++i) std::cin >> R[i];

    std::sort(R.begin(), R.end());

    int ans = 0;
    for(int i=0; i<N; ++i){
        ans += (i%2 == 0) ? (R[N-i-1]*R[N-i-1]) : -R[N-i-1]*R[N-i-1];
    }
    std::cout << std::fixed << std::setprecision(7) << ans * M_PI << std::endl;
}

