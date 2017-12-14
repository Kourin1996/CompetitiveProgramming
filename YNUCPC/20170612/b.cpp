#include <iostream>
#include <vector>

int N;
std::vector<std::string> S;
std::vector<int> P;

int main(void){
    int i;
    std::cin >> N;
    S.resize(N);
    P.resize(N);

    int sum = 0;
    int max = 0;
    std::string max_name;
    for(i=0; i<N; ++i){
        std::cin >> S[i] >> P[i];
        sum += P[i];

        if(max < P[i]){
            max = P[i];
            max_name = S[i];
        }
    }

    if(sum/2 < max){
        std::cout << max_name << std::endl;
    }else{
        std::cout << "atcoder\n";
    }
}
