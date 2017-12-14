#include <iostream>
#include <map>

using namespace std;

int A = 0, B = 0, C = 0;

map<int,int> mp;

int main(void){

    mp[5] = 0;
    mp[7] = 0;

    cin >> A >> B >> C;
    mp[A]++;
    mp[B]++;
    mp[C]++;

    if(mp[5] == 2 && mp[7] == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

