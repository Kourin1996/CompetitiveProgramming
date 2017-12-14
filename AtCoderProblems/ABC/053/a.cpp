#include <iostream>
int x = 0;
int main(void){
    std::cin >> x;
    std::cout << ((x<1200) ? "ABC" : "ARC") << std::endl;
}
