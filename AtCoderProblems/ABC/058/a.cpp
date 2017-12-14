#include <iostream>
#include <cmath>
int a = 0, b = 0, c = 0;
int main(void){
    std::cin >> a >> b >> c;
    std::cout << ( (b-a == c-b) ? "YES" : "NO" ) << std::endl;
}
