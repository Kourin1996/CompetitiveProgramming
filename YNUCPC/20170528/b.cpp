#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(long long int n);

void solve(long long int n){
    int i,j;

    long long int val;

    int vi = 0;
    vector<long long int> v(n/7*2+1);
    i = 0;
    while(7*i < n){
        for(j=0; j<=1; ++j){
            if(j == 0)  val = 7*i + 1;
            else        val = 7*i + 6;

            if(val > n) break;
            if(n % val == 0){
                v[vi++] = val;
            }
        }
        i++;
    }

    cout << n << ":";
    for(i=0; i<vi; ++i){
        if(isPrime(v[i])){
            cout << " " << v[i];
        }
    }
    cout << endl;
}

vector<long long int> memo;
bool isPrime(long long int n){
    if(memo.empty()) return true;
    if(find(memo.begin(), memo.end(), n) != memo.end()) return true;

    int i;
    int s = memo.size();
    bool f = true;
    for(i=0; i<s; ++i){
        if(n % memo[i] == 0){
            f = false;
            break;
        }
    }
    if(f){
        memo.push_back(n);
        return true;
    }else{
        return false;
    }
}

int main(void){
    long long int n = 0;
    while(cin >> n){
        if(n == 1) break;
        solve(n);
    }
}
