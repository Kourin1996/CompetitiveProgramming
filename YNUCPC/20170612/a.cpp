#include <iostream>
std::string s;
int main(void){
    std::cin >> s;
    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3]){
        std::cout << "SAME\n";
    }else{
        std::cout << "DIFFERENT\n";
    }
}
