#include <bits/stdc++.h>

int N;
std::string S;
int main() {
    std::cin >> N;
    std::cin >> S;

    int left = 0, depth = 0;
    for(int i=0; i<N; ++i) {
        char c = S[i];
        if(c == '(') {
            ++depth;
        }
        if(c == ')') {
            if(depth <= 0) {
                ++left;
            } else {
                --depth;
            }
        }
    }
    for(int i=0; i<left; ++i) {
        std::cout << "(";
    }
    std::cout << S;
    for(int i=0; i<depth; ++i) {
        std::cout << ")";
    }
    std::cout << std::endl;
}