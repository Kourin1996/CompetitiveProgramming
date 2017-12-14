#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N = 0;
int B[20] = {0};

long dp(int no){
    long mn = LONG_MAX;
    long mx = 0;

    long ret = 0;
    int cnt = 0;

    for(int i=0; i<N; ++i){
        if(B[i] == no){
            cnt++;

            ret = dp(i+1);
            mn  = min(mn, ret);
            mx  = max(mx, ret);
        }
    }
    return (cnt == 0) ? 1 : (mx+mn+1);
}

int main(void){
    cin >> N;

    for(int i=0; i<N; ++i){
        if(i == 0){
            B[i] = -1;
        }else{
            cin >> B[i];
        }
    }
    cout << dp(1) << endl;
}
