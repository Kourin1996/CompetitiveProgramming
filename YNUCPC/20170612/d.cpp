#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

const double e = std::numeric_limits<double>::epsilon();

int N;
std::vector<int> X;
std::vector<int> Y;

int main(void){
    std::cin >> N;

    int i, j, k;

    X.resize(N);
    Y.resize(N);
    for(i=0; i<N; ++i){
        std::cin >> X[i] >> Y[i];
    }

    long long int A = 0, B = 0, C = 0;
    for(i=0; i<N; ++i){
        std::vector<double> P;
        for(j=0; j<N; ++j){
            if( i==j ) continue;
            P.push_back(atan2(Y[j]-Y[i], X[j]-X[i]));
        }
        std::sort(P.begin(), P.end());

        for(j=0; j<N-1; ++j){
            P.push_back(P[j]+2*M_PI);
        }
        long long int y = 0, z = 0;
        for(int x=0; x<N-1; ++x){
            while(P[y]-P[x] < M_PI/2-e){
                y+=1;
            }
            while(P[z]-P[x] < M_PI+e){
                z+=1;
            }
            if( fabs(P[y]-P[x]-M_PI/2)<2*e ){
                B+=1;
                y+=1;
            }
            C += z-y;
        }
    }
    A = N*(N-1)*(N-2)/6-B-C;

    std::cout << A << " " << B << " " << C << std::endl;
}
