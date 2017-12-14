#include <iostream>

using namespace std;

int A = 0;
int x = 0, y = 0;
int m = 0;

int main(void){
    cin >> A;

    for(int i=0; i<=A; ++i){
        for(int j=0; j<=A; ++j){
            if((i+j) != A) continue;
            if((i*j) > m){
                m = i * j;
                x = i;
                y = j;
            }
        }
    }

    cout << x * y << endl;
}
