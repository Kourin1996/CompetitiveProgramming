#include <iostream>
long n;
int main(void){
    std::cin >> n;
    std::cout << ( (n%2 == 0) ? n-1 : n+1 ) << std::endl;
}
