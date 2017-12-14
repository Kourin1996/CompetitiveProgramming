#include <iostream>
int H, W;
int main(void){
    std::cin >> H >> W;
    std::cout << (H-1)*W + H*(W-1) << std::endl;
}
