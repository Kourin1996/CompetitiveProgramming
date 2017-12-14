#include <iostream>
int n = 0, X  = 0;
int main(void){
    int a = 0;

    int sum = 0;

    std::cin >> n >> X;
    for(int i=0; i<n; ++i){
        std::cin >> a;
        if(X % 2 == 1){
            sum += a;
        }
        X /= 2;
    }

    std::cout << sum << std::endl;
}
