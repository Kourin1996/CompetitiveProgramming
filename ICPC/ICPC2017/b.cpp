#include <iostream>
#include <string>
using namespace std;

void solve(const string& s1, const string& s2){
    int l1 = s1.length(), l2 = s2.length();
    int i = 0, j = 0;

    int mis = 0;
    while( i < l1 && j < l2 ){
        if( s1[i] == '"' && s2[j] == '"' ){
            ++i, ++j;

            int si = i, sj = j;
            while( si < l1 && s1[si] != '"' ) ++si;
            while( sj < l2 && s2[sj] != '"' ) ++sj;

            string sub1 = s1.substr(i, si-i);
            string sub2 = s2.substr(j, sj-j);

            if( sub1 != sub2 && ++mis > 1 ){
                cout << "DIFFERENT" << endl;
                return;
            }

            i = si + 1;
            j = sj + 1;

            continue;
        }

        if( s1[i] != s2[j] ){
            cout << "DIFFERENT" << endl;
            return;
        }

        ++i, ++j;
    }

    if( (l1-i) == (l2-j) ){
        if(mis == 0){
            cout << "IDENTICAL" << endl;
        }else{
            cout << "CLOSE" << endl;
        }
    }else{
        cout << "DIFFERENT" << endl;
    }
    return;
}

int main(void){
    std::string s1, s2;
    while(cin >> s1, !(s1.length() == 1 && s1[0] == '.')){
        cin >> s2;
        solve(s1,s2);
    }
}
