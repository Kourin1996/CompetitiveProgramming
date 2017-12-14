#include <iostream>
#include <vector>
int N;
std::vector< std::vector<char> > s;
int main(void){
    std::cin >> N;
    s.resize(N, std::vector<char>(N));
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            std::cin >> s[i][j];
        }
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            std::cout << s[N-j-1][i];
        }
        std::cout << std::endl;
    }
}
