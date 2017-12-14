#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 2222;
const double eps = 1e-10;
const double pi = acos(-1);
long long int x[MAXN], y[MAXN];

int main() {
    long long int N;
    cin >> N;

    if(N > 100) return 0;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    long long int sum = N*(N-1)*(N-2)/6;
    long long int cnt90 = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        vector<double> v;
        for (int j = 0; j < N; j++) {
            if (i==j) continue;
            v.push_back(atan2(y[j]-y[i], x[j]-x[i]));
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < N-1; j++) v.push_back(v[j]+2*pi);
        for (int j = 0; j < N-1; j++) {
            cnt90 += upper_bound(v.begin(), v.end(), v[j]+pi/2+eps) - lower_bound(v.begin(), v.end(), v[j]+pi/2-eps);
            cnt += lower_bound(v.begin(), v.end(), v[j]+pi) - upper_bound(v.begin(), v.end(), v[j]+pi/2+eps);
        }
    }
    cout << sum-cnt-cnt90 << " " << cnt90 << " " << cnt << endl;
    return 0;
}
