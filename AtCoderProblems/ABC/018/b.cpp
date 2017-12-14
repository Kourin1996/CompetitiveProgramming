#include <iostream>
#include <string>
#include <algorithm>

std::string S;
int N = 0;
int main(void){
    int l = 0, r = 0;

    std::string left, mid, right;

    std::cin >> S;
    std::cin >> N;
    for(int i=0; i<N; ++i){
        std::cin >> l >> r;

        left = S.substr(0, l-1);
        mid  = S.substr(l-1, r-l+1);
        right= S.substr(r, S.length()-r+1);

        std::reverse(mid.begin(), mid.end());

        S = (left + mid + right);
    }
    std::cout << S << std::endl;
}
