#include <iostream>
#include <cstdio>
using namespace std;
int m = 0;
int main(void){
    cin >> m;
    if(m < 100){
        printf("00\n");
    }else if(m >= 100 && m <= 5000){
        printf("%02d\n", m/100);
    }else if(m >= 6000 && m <= 30000){
        printf("%d\n", m/1000+50);
    }else if(m >= 35000 && m <= 70000){
        printf("%d\n", (m/1000-30)/5+80);
    }else{
        printf("89\n");
    }
}
