#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> E(6,0);
int B = 0;
vector<int> L(6,0);

int main(void){
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i=0; i<6; ++i){
        cin >> E[i];
    }
    cin >> B;
    for(int i=0; i<6; ++i){
        cin >> L[i];
    }

    sort(E.begin(), E.end());
    sort(L.begin(), L.end());

    for(int i=0; i<6; ++i){
        for(int j=0; j<6; ++j){
            if(E[i] == L[j]){
                cnt1++;
                goto outer;
            }else if(L[j] == B){
                cnt2++;
            }
        }
        outer:;
    }
    cout << (  cnt1 == 6 ? 1
              :(cnt1 == 5 && cnt2 > 0) ? 2
              :cnt1 < 3                ? 0
              :                          8-cnt1) << endl;
}
