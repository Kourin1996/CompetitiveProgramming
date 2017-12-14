#include <iostream>

using namespace std;

string S;
int main(void){
    cin >> S;
    cout << ((*(S.end()-1) == 'T') ? "YES" : "NO") << endl;
}
