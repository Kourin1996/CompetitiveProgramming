#include<bits/stdc++.h>

int a, b, c;
int solve() {
    int s = 0, t = 0;

    std::vector<bool> waked(61, false);
    while(true) {
        if(waked[s]) {
            return -1;
        }
        waked[s] = true;

        if(s <= c && c <= s+a) {
            break;
        }

        t += (a + b);
        s = (a+b+s)%60;
    }
    return t + c - s;
}

int main() {
    std::cin >> a >> b >> c;
    std::cout << solve() << std::endl;
}