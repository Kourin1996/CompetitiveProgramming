#include <iostream>
#include <algorithm>
int main(void){
    int max = 0;
    int x;
    while(std::cin >> x, x != 0){
        max = std::max(max, x);
    }
    std::cout << max << std::endl;
}
