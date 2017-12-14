#include <iostream>
int a = 0, b = 0;
int main(void){
    std::cin >> a >> b;
    std::cout <<((a%b == 0) ? 0 : (b - a%b)) << std::endl;
}
