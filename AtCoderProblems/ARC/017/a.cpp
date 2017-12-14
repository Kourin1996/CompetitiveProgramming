#include <iostream>
int N = 0;
int main(void){
    std::cin >> N;
    for(int i=2; i<N; ++i){
        if( N%i == 0 ){
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
    return 0;
}
