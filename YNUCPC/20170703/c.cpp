#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
int N;
std::vector<int> a;
int main(void){
    std::cin >> N;
    a.resize(N);

    for(int i=0; i<N; ++i){
        std::cin >> a[i];
        memo[a[i]] = -1;
    }

    std::vector<int> b(a);
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(),b.end()),b.end());

    auto _A_BEGIN = a.begin(), _A_END = a.end();
    auto _B_BEGIN = b.begin();

    for(auto it=_A_BEGIN ; it!=_A_END; ++it){
        auto index = std::lower_bound(b.begin(), b.end(), *it);
        std::cout << (index-_B_BEGIN) << std::endl;
    }
}
