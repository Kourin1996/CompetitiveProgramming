#include <iostream>
#include <algorithm>

int n = 0;
int main(void){
    int a, b, c, d;
    int cnt;
    while(std::cin >> n){
        cnt = 0;
        for(a=0; a<=1000; ++a){
            if(a > n) break;
            for(b=0; b<=n-a; ++b){
                if((a+b) > n) break;
                if(n-a-b > 2000) break;
                cnt += (n-a-b+1);
            }
        }
        std::cout << cnt << std::endl;
    }
}
