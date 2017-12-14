#include <iostream>
#include <algorithm>
#include <string>

int N = 0, A = 0, B = 0;
std::string s;
int d = 0;

int main(void){
    std::cin >> N >> A >> B;
    int ans = 0;
    for(int i=0; i<N; ++i){
        std::cin >> s >> d;
        d = std::max(A, std::min(B, d));
        ans += ((s == "East") ? d : -d);
    }
    std::cout << ((ans == 0) ? "0"
                 :(ans  > 0) ? ("East " + std::to_string(ans))
                 :             ("West " + std::to_string(-ans))) << std::endl;
}
