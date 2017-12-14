#include <iostream>
int N;
int main(void){
    std::cin >> N;
    std::cout << ((N/100 == N%10) ? "Yes" : "No") << std::endl;
}
