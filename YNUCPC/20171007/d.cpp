#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int R, N, M;
std::vector<double> cut;

int main(void){
    std::cin >> R >> N >> M;
    cut.resize(N+M+1, 0);

    for(int i=1; i<N; ++i){
        double x = 2.0 * R / N * i - R;
        cut[i] = 2 * std::sqrt(std::pow(R,2.0) - std::pow(x,2.0));
    }

    double ans = 0.0;
    for(int i=1; i < N + M; ++i){
        ans += std::max(cut[i], cut[std::max(i-M,0)]);
    }
    std::cout << std::fixed << std::setprecision(30) << ans << std::endl;
}

