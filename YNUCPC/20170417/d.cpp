#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int A = 0, B = 0, C = 0;

double func(double t){
    return A*t + B*sin(C*M_PI*t);
}

int main(void){
    cin >> A >> B >> C;

    double left  = (100.0 - B)/A;
    double right = (100.0 + B)/A;
    double mid   = (left+right)/2.0;
    double diff  = func(mid) - 100.0;

    while(right - left > 1e-12){
        if(diff < 0){
            left  = mid;
        }else{
            right = mid;
        }
        mid  = (left+right)/2.0;
        diff = func(mid) - 100.0;
    }
    printf("%.12lf\n",mid);
}
