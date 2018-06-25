#include <bits/stdc++.h>

std::vector<int> P(10000);

int main() {
    int m, nmin, nmax;
    int i;
    while(std::cin >> m >> nmin >> nmax) {
        if(m == 0 && nmin == 0 && nmax == 0) break;
        for(i=0; i<m; ++i) {
            std::cin >> P[i];
        }
        std::sort(P.begin(), P.begin()+i, std::greater<int>());

        int max = 0;
        int maxN = 0;
        for(i=nmax; i>=nmin; --i) {
            int gap = P[i-1] - P[i];
            if(gap > max) {
                max = gap;
                maxN = i;
            }
        }
        std::cout << maxN << std::endl;
    }
}