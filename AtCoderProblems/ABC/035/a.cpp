#include <iostream>

int W = 0, H = 0;

int main(void){
    std::cin >> W >> H;
    std::cout << (((W % 16 == 0) && (H % 9 == 0)) ? "16:9" : "4:3") << std::endl;
}
