#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;
int x = 0;

int main(void){
    cin >> n >> x;

    cout << min(x-1, n-x) << endl;
}
