#include <iostream>
#include <algorithm>

int N;
std::string S;

int main(void){
    std::cin >> N;
    std::cin >> S;

    int x = 0;
    int max = 0;
    for(auto it=S.begin(), _END=S.end(); it != _END; ++it){
        if(*it == 'I'){
            x += 1;
            max = std::max(max,x);
        }else{
            x -= 1;
        }
    }
    std::cout << max << std::endl;
}
