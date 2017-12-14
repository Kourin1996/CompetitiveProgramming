#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prime(1001,1);
vector<long long int> sum(1002, 0);

int main(void){

    int i,j;
    for(i=2; i<=1000; ++i){
        if(prime[i] == 0) continue;
        for(j=2; i*j <= 1000; ++j){
            prime[i*j] = 0;
        }
    }

    j = 1;
    for(i=2; i<=1000; ++i){
        if(prime[i] == 1){
            sum[j] = sum[j-1] + i;
            j++;
        }
    }

    int a;
    int n = 0;
    int cnt;
    while(cin >> n, n != 0){
        i = 1;
        cnt = 0;
        while(i <= 1000){
            if(sum[i] < n){
            }else if(sum[i] == n){
                cnt++;
            }else{
                for(j=1; j <= i; ++j){
                    if(2*n < sum[j]) break;
                    if(binary_search(sum.begin(), sum.end(), n-sum[j])){
                        cnt++;
                    }
                }
            }
            i++;
        }
        cout << cnt << endl;
    }
}
