#include <iostream>
#include <algorithm>

using namespace std;

int A = 0, B = 0;
int C = 0, D = 0;
int P = 0;

int main(void){
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;
    cin >> P;

    int x = A * P;
    int y = (P <= C) ? B : B + D*(P-C);

    cout << min(x,y) << endl;
}

