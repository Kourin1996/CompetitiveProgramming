#include <iostream>
#include <algorithm>

using namespace std;

int T = 0;
int N = 0;
int L[100000] = {0};


int main(void){
    cin >> T;
    for(int i=0; i<T; ++i){
        cin >> N;
        for(int j=0; j<N; ++j){
            cin >> L[j];
        }
        sort(L, L+N);
        int dis = 0;
        for(int j=0; j<N-1; ++j){
            dis = max(dis, L[j+1]-L[j]);
        }
        cout << dis << endl;
    }
}

