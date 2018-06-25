#include<bits/stdc++.h>

#define REP(i,a) for(long i=0;i<(a);++i)

typedef long long LL;

LL solve(const int n) {
    LL cnt = 0;
    
    LL val = n;
    std::string str = std::to_string(n);

    std::set<LL> set;
    while(str.length() > 1) {
        if(set.count(val) > 0) {
            return -1;
        }
        set.insert(val);

        int len = str.length();

        LL left = 0;
        LL right = std::atoll(str.c_str());
        LL max = 0;
        REP(i, len-1) {

            int x = str[i] - '0';
            left  = left*10 + x;
            right = right - x * std::pow(10, len-i-1);

            max = std::max(max, left*right);
        }
        val = max;
        str = std::to_string(max);

        ++cnt;
    }
    return cnt;   
}

int Q;
int main() {
    std::cin >> Q;
    REP(i, Q) {
        int N;
        std::cin >> N;
        LL res = solve(N);
        std::cout << res << std::endl;
    }
}