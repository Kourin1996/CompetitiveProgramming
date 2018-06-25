#include <bits/stdc++.h>


int n;
std::vector< std::string > ss;

inline int getDots(std::string s) {
    return s.rfind('.', s.length() - 1);
}

std::pair<long long, int> calc(int depth, int i) {
    int num = getDots(ss[i]) + 1;
    if(depth > num) {
        return {-1, i};
    }

    char c = ss[i][num];
    if(c >= '0' && c <= '9') {
        return {(long long)(c - '0'), i+1};
    }

    long long ans = (c == '+' ? 0 : 1);
    int j = i + 1;
    while(j < n) {
        auto res = calc(depth + 1, j);
        if(res.first == -1) {
            break;
        }
        if(c == '+') {
            ans += res.first;
        } else {
            ans *= res.first;
        }
        j = res.second;
    }
    return {ans, j};
}

int main() {
    ss.resize(100);
    while(std::cin >> n, n != 0) {
        for(int i=0; i<n; ++i) {
            std::cin >> ss[i];
        }
        std::cout << calc(0, 0).first << std::endl;
    }
}