#include <bits/stdc++.h>

int len[] = {5, 7, 5, 7, 7};
std::vector< std::string > w(40);

bool check(int start, int n) {
    int i = start, k;
    for(k = 0; k < 5; ++k) {
        int rest = len[k];

        if(i >= n) return false;
        while(i < n && rest > 0) {
            rest -= w[i].length();
            ++i;
        }
        if(rest < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    int i;
    while(std::cin >> n, n != 0) {
        for(i = 0; i < n; ++i) {
            std::cin >> w[i];
        }

        for(i = 0; i < n; ++i) {
            if(check(i, n)) {
                std::cout << i + 1 << std::endl;
                break;
            }
        }
    }
}