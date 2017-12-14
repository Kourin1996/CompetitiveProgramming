#include <iostream>
int N = 0;
std::string S;
int main(void){
    std::cin >> N;
    std::cin >> S;

    int m = N/2;
    bool flag = true;
    for(int i=m; i>=0; --i){
        if(i%3 == 1){
            if(S[m-i] != 'a' || S[N-m+i-1] != 'c'){
                std::cout << "-1" << std::endl;
                return 0;
            }
        }else if(i%3 == 2){
            if(S[m-i] != 'c' || S[N-m+i-1] != 'a'){
                std::cout << "-1" << std::endl;
                return 0;
            }
        }else{
            if(S[m-i] != 'b' || S[N-m+i-1] != 'b'){
                std::cout << "-1" << std::endl;
                return 0;
            }
        }
    }

    std::cout << m << std::endl;
}
