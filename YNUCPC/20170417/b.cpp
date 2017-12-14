#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

int N = 0;
double ans = 0.0;

int r[1000] = {0};
int sum = 0;

int main(void){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> r[i];
    }

    sort(r, r+N);

    int cnt = 0;

    for(int i=N-1; i>=0; --i){
        if(cnt%2 == 0){
            sum += r[i]*r[i];
        }else{
            sum -= r[i]*r[i];
        }
        cnt++;
    }

    printf("%.10lf\n", sum*M_PI);
}

