#include <bits/stdc++.h>

int N;
std::vector<int> color(9, 0);
int main() {
    std::cin >> N;

    int a;
    for(int i=0; i<N; ++i) {
        std::cin >> a;
        if(a >= 3200) {
            a = 3200;
        }
        ++color[a/400];
    }

    int cnt = 0;
    for(int i=0; i<8; ++i) {
        if(color[i] > 0) {
            ++cnt;
        }
    }

    int min = std::max(cnt, 1), 
        max = cnt + color[8];
    std::cout << min << " " << max << std::endl;
}