#include <iostream>

int N, L;
std::string S;

int main(void){
    std::cin >> N >> L;
    std::cin >> S;

    int tab = 1;
    int cnt = 0;
    for(auto it = S.begin(), _END = S.end(); it != S.end(); ++it){
        tab += (*it == '+') ? 1 : -1;
        if(tab > L){
            tab = 1;
            ++cnt;
        }
    }
    std::cout << cnt << std::endl;
}
