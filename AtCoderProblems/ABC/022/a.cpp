#include <iostream>
using namespace std;

int N = 0, S = 0, T = 0;
int W = 0;
int A = 0;

int main(void){
    cin >> N >> S >> T;
    cin >> W;

    int ans = (S <= W && W <= T) ? 1 : 0;
    for(int i=1; i<N; ++i){
        cin >> A;
        W += A;
        if(S <= W && W <= T){
            ans++;
        }
    }
    cout << ans << endl;
}

