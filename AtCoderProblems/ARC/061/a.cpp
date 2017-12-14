#include <bits/stdc++.h>

std::string S;
long long calc(int p) {
    unsigned char len = S.length();
    long long temp = 0;
    long long ans = 0;
    for(int i=0; i < len; ++i){
        temp = temp*10 + (S[i] - '0');
        if( (p >> (len-i-2)) & 0x01 ) {
            ans += temp;
            temp = 0;
        }
    }
    ans += temp;
    return ans;
}

int main(void){
    std::cin >> S;

    long long ans = 0;
    for(long i=0; i<std::pow(2, S.length()-1); i++) {
        ans += calc(i);
    }
    std::cout << ans << std::endl;
}
