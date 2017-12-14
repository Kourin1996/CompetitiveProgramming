#include <iostream>
#include <vector>
int L = 0, R = 0;
std::vector<int> left(40, 0);
int main(void){
    int l = 0, r = 0;
    std::cin >> L >> R;

    int ans = 0;
    for(int i=0; i<L; ++i){
        std::cin >> l;
        left[l]++;
    }
    for(int i=0; i<R; ++i){
        std::cin >> r;
        if(left[r] >= 1){
            left[r]--;
            ans++;
        }
    }
    std::cout << ans << std::endl;
}
