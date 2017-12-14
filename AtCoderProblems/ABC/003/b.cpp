#include <iostream>
std::string S, T;
int main(void){
    std::cin >> S;
    std::cin >> T;

    int cntS = 0;
    int cntT = 0;
    for(int i=0; i<S.length(); ++i){
        if(S[i] != T[i]){
            if(S[i] == '@' && (T[i] == 'a' || T[i] == 't' || T[i] == 'c' || T[i] == 'o' || T[i] == 'd' || T[i] == 'e' || T[i] == 'r')){
                cntS++;
            }else{
                cntS--;
            }
            if(T[i] == '@' && (S[i] == 'a' || S[i] == 't' || S[i] == 'c' || S[i] == 'o' || S[i] == 'd' || S[i] == 'e' || S[i] == 'r')){
                cntT++;
            }else{
                cntT--;
            }
        }
    }
    std::cout << ((cntS+cntT) == 0 ? "You can win" : "You will lose") << std::endl;
}
