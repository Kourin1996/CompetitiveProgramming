#include <bits/stdc++.h>

int n;
std::vector<char> cs(100);
std::map<char, int> map;
int main() {
    char c;
    while(std::cin >> n, n != 0) {
        for(int i=0; i<n; ++i) {
            std::cin >> cs[i];
        }

        bool f = true;
        map.clear();
        for(int i=0; i<n; ++i) {
            c = cs[i];
            if(map.count(c) == 0) {
                map.insert({c, 0});
            }
            map[c] = map[c] + 1;

            int fst = 0, snd = 0;
            char fstc;
            for(auto it: map) {
                if(fst < it.second) {
                    fst = it.second;
                    fstc = it.first;
                }
            }
            for(auto it: map) {
                if(fstc != it.first && snd < it.second) {
                    snd = it.second;
                }
            }

            int rest = n - i -1;
            if(fst > snd + rest) {
                std::cout << fstc << " " << i+1 << std::endl;
                f = false;
                break;
            }
        }
        if(f) {
            std::cout << "TIE" << std::endl;
        }
    }
}