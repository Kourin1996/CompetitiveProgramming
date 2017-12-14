#include <iostream>

int A = 0, B = 0;
char op;
int main(void){
    std::cin >> A >> op >> B;
    std::cout << ((op == '+') ? A+B : A-B) << std::endl;
}
