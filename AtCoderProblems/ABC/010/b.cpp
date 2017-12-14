#include <iostream>
int N = 0;
int a = 0;

int solve(int a){
    while( a%2 == 0 || a%3 == 2 ) --a;
    return a;
}

int main(void){
    int res = 0;

    std::cin >> N;
    for( int i=0; i<N; ++i ){
        std::cin >> a;
        res += (a - solve(a));
    }
    std::cout << res << std::endl;
}
