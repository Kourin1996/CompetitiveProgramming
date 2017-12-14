#include<bits/stdc++.h>

#define RREP(i,a) for(long i=(a);i>=0;--i)

std::string X;
int main() {
    std::cin >> X;

    int len = X.length();
    int t = 0, cnt = 0;
    RREP(i, len - 1) {
        if(X[i] == 'T') {
            t++;
        }
        if(X[i] == 'S') {
            if(t == 0) continue;
            t--, cnt++;
        }
    }
    std::cout << len - 2*cnt << std::endl;
}

