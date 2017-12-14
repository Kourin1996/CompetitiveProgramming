#include <iostream>
#include <vector>

using namespace std;

const int MAX = 3000000;

int day[MAX+1];
int isPrime[MAX+1];

int main(void){
    int i, j;
    for(i=0; i<MAX; ++i){
        day[i] = (i%7 == 1 || i%7 == 6);
        isPrime[i] = day[i];
    }

    for(i=6; i<=MAX; ++i){
        if(isPrime[i] == 0) continue;
        for(j=2; i*j <= MAX; ++j){
            if(day[j]) isPrime[i*j] = 0;
        }
    }

    int n;
    while(cin >> n){
        if(n == 1) break;
        cout << n << ":";
        for(i=2; i<=n; ++i){
            if(isPrime[i] && n%i == 0){
                cout << " " << i;
            }
        }
        cout << "\n";
    }
}
