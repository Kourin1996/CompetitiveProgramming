#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int N;
int main(void){
    std::cin >> N;
    while(N-- > 0){
        int n;
        std::cin >> n;
        std::vector<int> t(n+1);
        std::vector<int> sum(n+1, 0);
        for(int i=1; i<=n; ++i){
            std::cin >> t[i];
        }

        std::sort(t.begin()+1, t.end());
        sum[1] = t[1];
        for(int i=2; i<=n; ++i){
            sum[i] = t[i] + sum[i-1];
        }

        long long int ans = LLONG_MAX;
        for(int i=1; i<=n/3; ++i){
            for(int j=i+1; j<=n*2/3; ++j){
                long long int res = sum[i]*i + (sum[j]-sum[i])*(j-i) + (sum[n]-sum[j])*(n-j);
                ans = std::min(ans, res);
            }
        }
        std::cout << ans << std::endl;
    }
}
