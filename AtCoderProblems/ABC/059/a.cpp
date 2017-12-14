#include <iostream>
std::string s1, s2, s3;
int main(void){
    std::cin >> s1 >> s2 >> s3;
    std::cout << (char)(s1[0]-'a'+'A') << (char)(s2[0]-'a'+'A') << (char)(s3[0]-'a'+'A') << std::endl;
}
