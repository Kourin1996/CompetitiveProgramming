#include <iostream>

using namespace std;

int A = 0;
int B = 0;
int C = 0;

int main(void){
    cin >> A >> B >> C;
    cout << 2*(A*B + B*C + C*A) << endl;
}
