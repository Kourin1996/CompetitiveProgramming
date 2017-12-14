#include <iostream>
#include <cmath>
#include <algorithm>
long long int N = 0;

int getDigit(int n){
    return log10(n)+1;
}

long long int solve(){
    int digit = getDigit(N);

    long long int ans = 0;
    for(int i=1; i<=digit; ++i){
        long long int cycle = pow(10, i);

        ans += (N/cycle)*(cycle/10);

        long long int remain = (N+1)%cycle;
        remain = (remain == 0) ? cycle : remain;

        if(remain <= cycle/10){
        }else if(remain <= cycle/5){
            ans += remain - cycle/10;
        }else{
            ans += cycle/10;
        }
    }
    return ans;
}

int main(void){
    std::cin >> N;
    std::cout << solve() << std::endl;
}
