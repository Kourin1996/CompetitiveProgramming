#include <iostream>
#include <algorithm>
int n = 0;
int k = 0;
int main(void){
    std::cin >> n;
    std::cin >> k;
    std::cout << ( (n >= 2*k) ? "YES" : "NO") << std::endl;
}
