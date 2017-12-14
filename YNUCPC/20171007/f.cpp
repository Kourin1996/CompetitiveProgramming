#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int N, K;
std::map<long long,long long> map;
int main(void){
    std::cin >> N >> K;
    int a = 0;
    for(int i=0; i<N; ++i){
        std::cin >> a;
        map[std::__gcd(a,K)]++;
    }

    long long cnt1 = 0;
    long long cnt2 = 0;
    for(auto m: map){
        for(auto n: map){
            if((m.first*n.first) % K == 0){
                if(m.first == n.first){
                    cnt1 += m.second * (n.second - 1);
                } else {
                    cnt2 += m.second * n.second;
                }
            }
        }
    }
    std::cout << (cnt1+cnt2)/2 << std::endl;
}