#include <iostream>
#include <algorithm>
using namespace std;

int N = 0;
int cnt[5] {0};

int main(void){
    char ci = 0;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> ci;
        cnt[ci - '0']++;
    }

    int mx = 0;
    int mn = N;

    for(int i=1; i<5; ++i){
        mx = max(mx, cnt[i]);
        mn = min(mn, cnt[i]);
    }

    cout << mx << " " << mn << endl;
}
