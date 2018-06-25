#include <bits/stdc++.h>

int n;
std::set<char> vowel {'a', 'i', 'u', 'e', 'o'};
std::vector< std::vector<char> > code(50, std::vector<char>(50));
int main() {
    int i, j, k, l, maxl;
    std::string s;
    while(std::cin >> n, n != 0) {
        maxl = 0;
        for(i = 0; i < n; ++i) {
            std::cin >> s;
            code[i].clear();
            l = s.length();
            for(j = 0; j < l; ++j) {
                if(j == 0 || vowel.count(s[j - 1]) > 0) {
                    code[i].push_back(s[j]);
                }
            }
            maxl = std::max(maxl, (int)code[i].size());
        }

        std::set< std::string > used;
        k = 0;

        int ans = -1;
        while(++k <= maxl) {
            used.clear();

            for(i = 0; i < n; ++i) {
                s = std::string(code[i].begin(), code[i].begin() + std::min(k, (int)code[i].size()));
                used.insert(s);
            }
            if(used.size() == n) {
                ans = k;
                break;
            }
        }
        std::cout << ans << std::endl;
    }
}