#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prime(10000,1);
vector<long long int> ans;

int main(void){

    int i,j;
    for(i=2; i<=10000; ++i){
        if(prime[i] == 0) continue;
        for(j=2; i*j <= 10000; ++j){
            prime[i*j] = 0;
        }
    }

    ans.resize(10002, 0), ans[0] = 1;

    for(i=0; i<prime.size(); ++i){
        int tmp = 0;
        for(j=0; i+j < prime.size(); ++j){
            tmp += prime[i+j];
            if(tmp > 10001) break;
            ++ans[tmp];
        }
    }

    long long int n = 0;
    while(cin >> n, n != 0){
        cout << ans[n] << endl;
    }
}
