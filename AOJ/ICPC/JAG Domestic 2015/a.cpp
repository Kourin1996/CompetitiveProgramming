#include <bits/stdc++.h>

int main() {
    int D, E;
    int x, y;
    while(std::cin >> D >> E, D != 0 && E != 0) {
        double min = std::numeric_limits<double>::max();
        for(x = 0; x <= D; ++x) {
            y = D - x;
            min = std::min(min, std::fabs(std::sqrt(x*x+y*y)-E));
        }
        std::cout << std::fixed << std::setprecision(5) << min << std::endl;
    }
}