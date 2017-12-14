#include <iostream>
std::string S;
int main(void){
    int cnt = 0;
    for(int i=0; i<12; ++i){
        std::cin >> S;
        if(S.find("r") != std::string::npos){
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}
