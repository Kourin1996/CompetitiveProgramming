#include <iostream>
#include <algorithm>
int a, b, c;
int main(void){
    std::cin >> a >> b >> c;
    std::cout << std::min(a+b, std::min(b+c, c+a)) << std::endl;
}
