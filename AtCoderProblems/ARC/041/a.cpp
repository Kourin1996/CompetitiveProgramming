#include <iostream>
#include <algorithm>

int x = 0, y = 0;
int k = 0;
int main(void){
    std::cin >> x >> y;
    std::cin >> k;

    int r = std::min(k, y);
    k -= r;
    x = x - k + r;

    std::cout << x << std::endl;
}
