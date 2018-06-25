#include <bits/stdc++.h>

int main() {
    int R0, W0, C, R;
    while(std::cin >> R0 >> W0 >> C >> R) {
        if(R0 == 0 && W0 == 0 && C == 0 && R == 0) break;
        std::cout << std::max(0, (C*W0-R0+R-1)/R) << std::endl;
    }
}