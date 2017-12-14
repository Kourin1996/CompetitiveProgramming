#include <iostream>
std::string S;
int cnt[10000] = {0};
int main(void){
    std::cin >> S;
    for(std::string::iterator ite = S.begin(); ite != S.end(); ite++){
        char c = *ite;
        cnt[c]++;
    }

    std::cout << cnt[(int)'A'] << " ";
    std::cout << cnt[(int)'B'] << " ";
    std::cout << cnt[(int)'C'] << " ";
    std::cout << cnt[(int)'D'] << " ";
    std::cout << cnt[(int)'E'] << " ";
    std::cout << cnt[(int)'F'] << std::endl;
}
