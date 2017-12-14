#include <iostream>

std::string S;
int A, B, C, D;

int main(void){
    std::cin >> S;
    std::cin >> A >> B >> C >> D;
    int cnt = 0;
    for(int i=0; i<S.length(); ++i){
        if(i == A || i == B || i == C || i == D){
            cnt++;
            std::cout << "\"";
        }
        std::cout << S[i];
    }
    std::cout << std::string("\"", 4-cnt);
    std::cout << std::endl;
}
