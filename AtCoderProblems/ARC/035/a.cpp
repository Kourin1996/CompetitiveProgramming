#include <iostream>
#include <string>

std::string s;

int main(void){
    std::cin >> s;
    int len = s.length();
    for(int i=0, hl = len/2; i<hl; ++i){
        if(s[i] == s[len-i-1]) continue;
        if(s[i] == '*' || s[len-i-1] == '*') continue;

        std::cout << "NO" << std::endl;
        return 0;
    }
    std::cout << "YES" << std::endl;
    return 0;
}
