#include<bits/stdc++.h>

std::string S;
int d1 = 5;
int d2 = 7;
int e1 = 5;
int e2 = 6;
int len = 0;

bool parse(int i) {
    if(i >= len) return true;

    if(S[i] == 'd') {
        if(S.substr(i, d1) == "dream") {
            bool r1 = parse(i + d1);
            if(r1) {
                return true;
            } else if(S.substr(i, d2) == "dreamer") {
                bool r2 = parse(i + d2);
                if(r2) {
                    return true;
                }
            }
        }
    } else if(S[i] == 'e') {
        if(S.substr(i, e1) == "erase") {
            bool r3 = parse(i + e1);
            if(r3) {
                return true;
            } else if(S.substr(i, e2) == "eraser") {
                bool r4 = parse(i + e2);
                if(r4) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    std::cin >> S;
    len = S.length();

    bool res = parse(0);
    if(res) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}