#include <iostream>
std::string s;
int main(void){
    std::cin >> s;
    int l = s.length();
    std::cout << s[0] << (l-2) << s[l-1] << std::endl;
}
