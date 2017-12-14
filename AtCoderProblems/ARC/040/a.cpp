#include <iostream>
int N = 0;
std::string S;
int main(void){
    int R = 0;
    int B = 0;

    std::cin >> N;
    for(int i=0; i<N; ++i){
        std::cin >> S;
        for(auto it = S.begin(), _END = S.end(); it != _END; ++it){
            if(*it == 'R') R++;
            else if(*it == 'B') B++;
        }
    }

    std::cout << ( (R == B) ? "DRAW"
                  :(R >  B) ? "TAKAHASHI"
                  :           "AOKI" ) << std::endl;
}
