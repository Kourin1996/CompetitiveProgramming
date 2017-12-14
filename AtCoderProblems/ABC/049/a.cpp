#include <iostream>
char c = 0;
int main(void){
    std::cin >> c;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        std::cout << "vowel" << std::endl;
    }else{
        std::cout << "consonant" << std::endl;
    }
}
