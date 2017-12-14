#include <iostream>
int N = 0;
int main(void){
    std::cin >> N;
    std::cout << ((N%3 == 0) ? "YES" : "NO") << std::endl;
}
