#include <iostream>
char c[4][4];
int main(void){
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            std::cin >> c[i][j];
        }
    }

    for(int i=3; i>=0; --i){
        for(int j=3; j>=0; --j){
            std::cout << c[i][j];
            if(j > 0){
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
