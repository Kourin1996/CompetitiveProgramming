#include <bits/stdc++.h>

struct S {
    int w, h, diag;
    S(int w, int h):w(w),h(h) {
        diag = h*h + w*w;
    }
    bool operator < (const S &s) const {
        if(diag < s.diag) return true;
        if(diag > s.diag) return false;
        return h < s.h;
    }
};

std::vector<S> vs;
int main() {
    vs.reserve(10005);
    int i, j;
    for(i = 1; i <= 200; ++i) for(j = i + 1; j <= 200; ++j) {
        vs.push_back(S(j, i));
    }
    std::sort(vs.begin(), vs.end());

    int h, w;
    while(std::cin >> h >> w, h != 0 && w != 0) {
        auto it = std::lower_bound(vs.begin(), vs.end(), S(w, h));
        std::cout << (*(it+1)).h << " " << (*(it + 1)).w << std::endl;
    }

    return 0;
}