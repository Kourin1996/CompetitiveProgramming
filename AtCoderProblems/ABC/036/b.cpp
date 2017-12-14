#include <iostream>

int N = 0;
char s[51][51];

int main(void){
    int i, j;
    std::cin >> N;
    for(i=0; i<N; ++i) std::cin >> s[i];

    for(i=0; i<N; ++i){
        for(j=0; j<N; ++j){
            std::cout <<  s[N-1-j][i];
        }
        std::cout << "\n";
    }
}
