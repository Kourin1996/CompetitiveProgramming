#include <iostream>
#include <string>

std::string s;

int main(void){
    std::cin >> s;
    std::cout << s.rfind('Z') - s.find('A') + 1 << std::endl;
}
