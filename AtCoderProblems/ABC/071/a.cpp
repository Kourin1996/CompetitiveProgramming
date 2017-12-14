#include <iostream>
#include <algorithm>
#include <cstdlib>

int x, a, b;
int main(void){
    std::cin >> x >> a >> b;

    if(std::abs(x-a) < std::abs(x-b)){
        std::cout << "A" << std::endl;
    }else{
        std::cout << "B" << std::endl;
    }
}
