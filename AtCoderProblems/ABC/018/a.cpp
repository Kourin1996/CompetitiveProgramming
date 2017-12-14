#include <iostream>

using namespace std;

int A = 0, B = 0, C = 0;

int mRank(int x, int y, int z){
    return  (x>y && x>z) ? 1
           :(x<y && x<z) ? 3
           :               2;
}

int main(void){
    cin >> A >> B >> C;
    cout << mRank(A,B,C) << endl;
    cout << mRank(B,C,A) << endl;
    cout << mRank(C,A,B) << endl;
}
