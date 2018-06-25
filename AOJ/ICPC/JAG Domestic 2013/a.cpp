#include <bits/stdc++.h>

inline char shift(char c, int x) {
    int d;
    char nc;
    if(c >= 'a' && c <= 'z') {
        nc = (char)(c - x);
        if(nc >= 'a' && nc <= 'z') {
            return nc;
        }
        d = 'a' - nc;
        return shift('Z', d - 1);
    } else {
        nc = (char)(c - x);
        if(nc >= 'A' && nc <= 'Z') {
            return nc;
        }
        d = 'A' - nc;
        return shift('z', d - 1);
    }
} 

int main() {
    int n;
    std::vector<int> k(100);
    std::string s;

    int i, l;
    while(std::cin >> n, n != 0) {
        for(i = 0; i < n; ++i) {
            std::cin >> k[i];
        }
        std::cin >> s;

        l = s.length();
        for(i = 0; i < l; ++i) {
            std::cout << shift(s[i], k[i % n]);
        }
        std::cout << std::endl;
    }
}