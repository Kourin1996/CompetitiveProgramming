#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int N = 0;
std::vector<double> point;

int main(void){
    int a, b, c, d, e;
    std::cin >> N;
    point.resize(N, 0.0);
    for(int i=0; i<N; ++i){
        std::cin >> a >> b >> c >> d >> e;
        point[i] = a + b + c + d + (1.*e*110)/900;
    }
    std::sort(point.begin(),
              point.end(),
              [](const double x, const double y){return x > y;});

    std::cout << std::fixed << std::setprecision(5)
              << point[0] << std::endl;
}
