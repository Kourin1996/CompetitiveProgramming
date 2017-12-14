#include <iostream>
#include <string>
std::string S;
const int N = 12;
int main(void){
    int cnt = 0;
    for(int i=0; i<N; ++i){
        std::cin >> S;
        cnt += ((int)S.find("r") >= 0);
    }
    std::cout << cnt << std::endl;
}
