#include <iostream>
#include <string>
#include <algorithm>
std::string S;
int main(void){
    std::cin >> S;
    std::transform(S.begin(), S.begin()+1, S.begin(), toupper);
    std::transform(S.begin()+1, S.end(), S.begin()+1, tolower);
    std::cout << S << std::endl;
}
