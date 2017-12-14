#include <iostream>
int n = 0;
int main(void){
    std::cin >> n;
    int sum = ((1+n)*n)/2;

    if(sum == 1){
        std::cout << "BOWWOW" << std::endl;
        return 0;
    }
    for(int i=2; i<sum; ++i){
        if(sum % i == 0){
            std::cout << "BOWWOW" << std::endl;
            return 0;
        }
    }
    std::cout << "WANWAN" << std::endl;
}
