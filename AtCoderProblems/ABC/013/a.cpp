#include <iostream>
char X;
int main(void){
    std::cin >> X;
    std::cout << (int)(X-'A'+1) << std::endl;
}
