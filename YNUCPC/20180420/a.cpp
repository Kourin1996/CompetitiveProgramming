#include <bits/stdc++.h>
int X, A, B;
int main(void){
    std::cin >> X >> A >> B;
    if(B-A <= 0){
        std::cout << "delicious" << std::endl;
    }else if(B-A >= X+1){
        std::cout << "dangerous" << std::endl;
    }else{
        std::cout << "safe" << std::endl;
    }
}