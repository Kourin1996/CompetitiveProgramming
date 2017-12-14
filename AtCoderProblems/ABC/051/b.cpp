#include <iostream>
#include <algorithm>

int K = 0, S = 0;

int main(void){
    std::cin >> K >> S;
    int X,Y,Z;
    long long int ans = 0;
    for(X=0;X<=K;++X){
        if(X > S) break;
        for(Y=0;Y<=K;++Y){
            Z = S-X-Y;
            if(Z < 0) break;
            if(Z<= K) ans++;
        }
    }
    std::cout << ans << std::endl;
}
