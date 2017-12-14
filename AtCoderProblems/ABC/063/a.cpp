#include <iostream>
#include <string>
int A, B;
int main(void){
    std::cin >> A >> B;
    std::cout << (A+B<10 ? std::to_string(A+B) : "error") << std::endl;
}
