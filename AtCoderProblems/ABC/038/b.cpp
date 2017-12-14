#include <iostream>
#include <algorithm>

int H1 = 0, W1 = 0;
int H2 = 0, W2 = 0;

int main(void){
    std::cin >> H1 >> W1;
    std::cin >> H2 >> W2;

    if( (H1==H2) || (W1==W2) || (W1==H2) || (H1==W2) ){
        std::cout << "YES\n";
    }else{
        std::cout << "NO\n";
    }
}
