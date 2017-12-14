#include <iostream>
#include <string>
#include <vector>

std::string S;

bool solve(std::string str){
    for(auto it=str.begin(), _END=str.end(); it != _END; ++it){
        if(*it == '0'){
            return false;
        }
    }
    return true;
}

int main(void){
    std::cin >> S;

    int len  = S.length();
    int left = 0;
    int right = 0;

    int cnt = 0;
    while(left < len){
        while(right < len && S[right] != '+') right++;

        std::string sub = S.substr(left, right-left);

        if(solve(sub)){
            ++cnt;
        }

        if(right >= len) break;

        left = right = right+1;
    }

    std::cout << cnt << std::endl;
}
