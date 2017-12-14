#include <iostream>
#include <algorithm>
long X, t;
int main(void){
    std::cin >> X >> t;
    std::cout << std::max(0L, X-t) << std::endl;
}
