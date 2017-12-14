#include <iostream>
int N = 0, A = 0, B = 0;
int main(void){
    std::cin >> N >> A >> B;
    N %= (A+B);
    std::cout << (( 0 < N && N <= A) ? "Ant" : "Bug") << std::endl;
}
