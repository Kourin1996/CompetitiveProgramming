#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cfloat>
#include <cmath>

int N;
std::vector<int> a;

int main(void){
    std::cin >> N;
    a.resize(N);
    for(int i=0; i<N; ++i){
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    double ave = (1.*std::accumulate(a.begin(), a.end(), 0))/a.size();
    int mid = 0;
    long ans = 0.0;

    if(fabs(ave - (int)ave) < DBL_EPSILON){
        mid = ave;
        std::transform(a.begin(), a.end(), a.begin(), [&](int x){return (x-mid)*(x-mid);});
        ans = std::accumulate(a.begin(), a.end(), 0);
    }else{
        std::vector<int> b(a);

        mid = ave;
        std::transform(a.begin(), a.end(), a.begin(), [&](int x){return (x-mid)*(x-mid);});

        mid += 1;
        std::transform(b.begin(), b.end(), b.begin(), [&](int x){return (x-mid)*(x-mid);});

        ans = std::min(std::accumulate(a.begin(), a.end(), 0), std::accumulate(b.begin(), b.end(), 0));
    }

    std::cout << ans << std::endl;
}
