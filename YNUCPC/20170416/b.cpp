#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;

int main(void){
    cin >> N;
    cin >> M;

    vector<int> A(M, 0);
    vector<int> P(N, 0);

    int target = 0;
    int count  = 0;
    int x = 0;
    int z = 0;

    for(int i=0; i<M; ++i){
        cin >> A[i];
    }

    for(int i=0; i<M; ++i){
        target = A[i];

        count = 0;
        for(int j=0; j<N; ++j){
            cin >> x;

            if(x == target){
                P[j] += 1;
                count++;
            }
        }

        P[target - 1] += (N - count);
    }

    for(int i=0; i<N; ++i){
        cout << P[i] << endl;
    }
}
