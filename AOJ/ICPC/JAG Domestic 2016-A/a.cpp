#include <bits/stdc++.h>

int main() {
    int N;
    std::string S;
    bool res = true;
    int cnt = 0;

    std::cin >> N;
    for(int i = 0; i < N; ++i) {
        std::cin >> S;
        if(S == "A") {
            ++cnt;
        } else if(S == "Un") {
            --cnt;
        }

        if(res && cnt < 0) {
            res = false;
        }
    }
    if(res && cnt == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}