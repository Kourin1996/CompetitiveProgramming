#include<bits/stdc++.h>
int main() {
    long long x;
    std::cin >> x;
    std::cout << x/11*2 + ( x%11==0 ? 0 : (x%11 <= 6 ? 1 : 2) ) << std::endl;
}