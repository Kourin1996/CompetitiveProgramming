#include <iostream>
int A[4][4];
int main(void){
    bool f = false;
    for(int i=0;i<4;++i){
        for(int j=0; j<4; ++j){
            std::cin >> A[i][j];
            if(j > 0){
                if(A[i][j] == A[i][j-1]){
                    f = true;
                    break;
                }
            }
            if(i > 0){
                if(A[i][j] == A[i-1][j]){
                    f = true;
                    break;
                }
            }
        }
        if(f) break;
    }
    std::cout << (f ? "CONTINUE" : "GAMEOVER") << std::endl;
}
