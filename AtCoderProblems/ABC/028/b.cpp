#include <iostream>
#include <map>
std::string S;

char p[] = {'A', 'B', 'C', 'D', 'E', 'F'};

int main(void){
    std::cin >> S;

    std::map<char,int> cnt;
    for(auto it = S.begin(), _END = S.end(); it != _END; ++it){
        cnt[*it]++;
    }
    for(int i=0; i<6; ++i){
        std::cout << (i ? " " : "") << cnt[p[i]];
    }
    std::cout << std::endl;
}
