#include<bits/stdc++.h>

long X;
int main() {
    std::cin >> X;
    long res = (std::sqrt(1+8*X) - 1)/2;
    while(res*(res+1) < 2*X) res++;
    std::cout << res << std::endl;
}


