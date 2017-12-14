#include <iostream>
#include <algorithm>
#include <cstdlib>

int a = 0, b = 0;
int main(void){
    std::cin >> a >> b;
    std::cout << std::min( std::abs(a-b), ( std::min(a,b) - std::max(a,b) + 10) ) << std::endl;

}
