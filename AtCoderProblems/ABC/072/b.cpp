#include <iostream>
std::string s;
int main(void){
    std::cin >> s;
    for(int i=0; i<s.length(); ++i){
        if(i % 2 == 0){
            std::cout << s[i];
        }
    }
    std::cout << std::endl;
}
