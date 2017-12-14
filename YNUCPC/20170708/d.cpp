#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<double> X;
vector<double> R;

bool in(double y){
    double l = -1e9, r = 1e9;
    for(int i=0; i<N; ++i){
        double dx = sqrt(R[i]*R[i]-y*y);

        l = max(l, X[i]-dx);
        r = min(r, X[i]+dx);
    }
    return (l<r);
}

int main(void){
    cin >> N;
    X.resize(N);
    R.resize(N);

    double down=0, mid, up = 1e9;
    for(int i=0; i<N; ++i){
        cin >> X[i] >> R[i];
        up = min(up, (double)R[i]);
    }

    for(int i=0; i<100; ++i){
        mid = (down+up)/2;
        if(in(mid)){
            down = mid;
        }else{
            up = mid;
        }
    }

    cout << fixed << setprecision(10) << down << std::endl;
}
