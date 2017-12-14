#include <iostream>

long long int N;
const int num = 6;
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void){
    std::cin >> N;

    int ary[6];

    int a = (N%30)/5;
    int b = N%5;

    int i;
    for(i=0; i<num-a; ++i){
        ary[i] = i+a+1;
    }
    for(i=0; i<a; ++i){
        ary[num-a+i] = i+1;
    }

    for(i=0; i<b; ++i){
        swap(ary+i, ary+i+1);
    }

    for(i=0; i<num; ++i){
        std::cout << ary[i];
    }
    std::cout << std::endl;
}
