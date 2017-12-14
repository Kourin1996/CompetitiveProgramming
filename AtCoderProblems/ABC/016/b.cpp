#include <iostream>
int A = 0, B = 0, C = 0;
int main(void){
    std::cin >> A >> B >> C;
    std::cout << ( (((A+B) == C) && ((A-B) == C)) ? '?'
                  : ((A+B) == C)                  ? '+'
                  : ((A-B) == C)                  ? '-'
                  :                                 '!')
              << std::endl;
}
