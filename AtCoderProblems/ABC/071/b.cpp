#include <iostream>
#include <vector>
#include <climits>
std::string S;
int main(void){
    std::cin >> S;

    auto memo = std::vector<int>(CHAR_MAX+1, 0);
    for(auto it=S.begin(), _END=S.end(); it!=_END; ++it){
        memo[*it]++;
    }

    bool f = false;
    for(char c = 'a'; c <= 'z'; ++c){
        if(memo[c] == 0){
            std::cout << c << std::endl;
            f = true;
            break;
        }
    }
    if(!f){
        std::cout << "None" << std::endl;
    }
}
