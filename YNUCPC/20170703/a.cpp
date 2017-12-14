#include <iostream>
int A,B;
int main(void){
    std::cin >> A >> B;
    std::cout << (B/A+(B%A!=0)) << std::endl;
}
