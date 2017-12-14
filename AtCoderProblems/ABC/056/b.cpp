#include <iostream>
#include <cstdlib>
#include <algorithm>
int W,a,b;

int main(void){
    std::cin >> W >> a >> b;
    if(a+W < b){
        std::cout << std::abs(b-a-W);
    }else if(b+W < a){
        std::cout << std::abs(a-b-W);
    }else{
        std::cout << 0;
    }
    std::cout << std::endl;
}
