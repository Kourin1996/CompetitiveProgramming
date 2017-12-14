#include <iostream>

int h = 0, m = 0;

int main(void){
    std::cin >> h >> m;
    std::cout << (18-h)*60 - m << std::endl;
}
