#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

bool cmp(const int &lhs, const int &rhs){
    return lhs > rhs;
}

int main(){
    int T;
    std::cin >> T;

    while(T--){
        int n;
        std::cin >> n;
        std::vector<int> a(n, 0);
        for(int i = 0; i < n; ++i){
            std::cin >> a[i];
        }

        sort(a.begin(), a.end(), cmp);

        std::vector<long long int> sum(n, 0);
        sum[0] = a[0];
        for(int i = 1; i < n; ++i){
            sum[i] = a[i] + sum[i-1];
        }

        long long int ans = LLONG_MAX;
        for(int i = 0; i < n/3; ++i){
            for(int j = i+1; j < n*2/3; ++j){
                int k = n - j;
                ans = std::min(ans, (long long int)0 + sum[i]*(i) + (sum[j]-sum[i])*(j-i) + (sum[n]-sum[j]) * k);
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
