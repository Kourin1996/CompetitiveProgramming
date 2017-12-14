#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string S1, S2, S3;
int N;
std::vector<long long> cnt1, cnt2, cnt3;
int main(void){
    std::cin >> S1 >> S2 >> S3;
    N = S1.length()/2;

    cnt1.resize(26, 0);
    cnt2.resize(26, 0);
    cnt3.resize(26, 0);

    for(int i=0; i<N*2; ++i){
        cnt1[S1[i]-'A']++;
        cnt2[S2[i]-'A']++;
        cnt3[S3[i]-'A']++;
    }

    long long l = 0, r = 0;
    for(int i=0; i<26; ++i){
        if(cnt1[i] + cnt2[i] < cnt3[i]){
            std::cout << "NO" << std::endl;
            return 0;
        }

        long long ll = std::max(0ll, cnt3[i]-cnt2[i]);
        long long rr = std::min(cnt1[i], cnt3[i]);

        l += ll;
        r += rr;
    }

    if(l <= N && N <= r){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    return 0;
}
