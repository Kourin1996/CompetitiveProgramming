#include <iostream>
#include <vector>
#include <utility>
#include <boost/multiprecision/cpp_int.hpp>

int N = 0, a = 0;
unsigned long long int k = 0;
std::vector<int> b;
std::vector<int> cnt;

int main(void){
    std::cin >> N >> a;
    std::cin >> k;

    b.resize(N+1, 0);
    cnt.resize(N+1, 0);

    long long int i;
    for(i=1; i<=N; ++i){
        std::cin >> b[i];
    }

    int no = a;
    long long int step = 0;
    long long int num = 0;
    long long int num_c = 0;
    while(true){
        if(cnt[no] == 0) num++;
        if(++cnt[no]>2)  break;

        no = b[no];
        ++step;
    }

    for(int i=1; i<=N; ++i){
        if(cnt[i] >= 2) num_c++;
    }

    if(k <= (num-num_c)){
    }else{
        k = (k-(num-num_c)) % num_c + (num-num_c);
    }

    no = a;
    for(i=1; i<=k; ++i){
        no = b[no];
    }

    std::cout << no << std::endl;
}
