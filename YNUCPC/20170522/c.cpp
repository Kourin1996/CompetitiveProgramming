#include <iostream>
#include <vector>

int N = 0, M = 0;
int X = 0, Y = 0;

std::vector<int> a;
std::vector<int> b;

int main(void){
    std::cin >> N >> M;
    std::cin >> X >> Y;

    a.resize(N);
    b.resize(M);

    int i;
    for(i=0; i<N; ++i) std::cin >> a[i];
    for(i=0; i<M; ++i) std::cin >> b[i];

    int time = 0;
    int cnt  = 0;

    auto ita = a.begin();
    auto itb = b.begin();
    auto enda= a.end();
    auto endb= b.end();
    while(ita != enda || itb != endb){
        while(*ita < time && ita != enda) ita++;
        if(ita == enda) break;

        time = *ita + X;

        while(*itb < time && itb != endb) itb++;
        if(itb == endb) break;

        time = *itb + Y;

        cnt++;
    }
    std::cout << cnt << std::endl;
}
