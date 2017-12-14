#include <iostream>
#include <vector>
int N = 0, M = 0;
int main(void){
    while(std::cin >> N >> M){
        if(N==0 && M==0) return 0;
        std::vector<int> mas(N, 0);
        for(int i=0; i<N; ++i){
            std::cin >> mas[i];
        }

        std::vector<int> me(M, 0);
        for(int i=0; i<M; ++i){
            std::cin >> me[i];
        }

        int point = 0;
        int cnt = 0;
        for(int i=0; i<M; ++i){
            cnt++;
            point += me[i];
            point += mas[point];
            if(point >= N) break;
        }
        std::cout << cnt << std::endl;
    }
}
