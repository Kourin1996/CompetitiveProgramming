#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

int N = 0;
vector< pair<int,int> > p;

int main(void){
    int x = 0, y = 0;

    cin >> N;
    p.resize(N);

    for(int i=0; i<N; ++i){
        cin >> x >> y;
        p[i] = make_pair(x,y);
    }

    int dis = 0;
    int res = 0;
    for(int i=0; i<N; ++i){
        for(int j=N-1; j>i; --j){
            dis = pow(p[i].first - p[j].first, 2.0) + pow(p[i].second-p[j].second, 2.0);
            res = max(res, dis);
        }
    }
    cout << fixed <<setprecision(10) << sqrt(1.*res) << endl;
}
