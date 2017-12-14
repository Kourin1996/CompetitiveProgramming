#include <iostream>
int N = 0;

bool isPrime(const unsigned int n){
    if(n <= 1) return false;
    if(n == 2) return true;
    for(int i=2; i<n; ++i){
        if(n%i == 0) return false;
    }
    return true;
}

int main(void){
    std::cin >> N;

    if( isPrime(N) || (N != 1 && N%2 != 0 && N%3 != 0 && N%5 != 0) ){
        std::cout << "Prime\n";
    }else{
        std::cout << "Not Prime\n";
    }
}
