#include <iostream>
#include <map>
#include <utility>
#include <cstdlib>
#include <algorithm>

std::string S;
int T;

std::map<char,int> cnt;

int main(void){
    std::cin >> S;
    std::cin >> T;

    cnt['L'] = cnt['R'] = cnt['U'] = cnt['D'] = cnt['?'] = 0;
    for(auto it = S.begin(), _END = S.end(); it != _END; ++it){
        ++cnt[*it];
    }

    int x = (-1)*cnt['L'] + cnt['R'];
    int y = (-1)*cnt['D'] + cnt['U'];

    for(int i=0; i<cnt['?']; ++i){
        if(T == 1){
            x += (x < 0) ? -1 : 1;
        }else{
            if(x != 0){
                x += (x < 0) ? 1 : -1;
            }else{
                y += (y < 0) ? 1 : -1;
            }
        }
    }

    std::cout << (std::abs(x) + std::abs(y)) << std::endl;
}
