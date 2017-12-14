#include <iostream>

using namespace std;
int N = 0;
string s;

int main(void){
    int res = 0;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> s;
        if(s[s.length()-1] == '.'){
            s = s.substr(0, s.length()-1);
        }
        if(s == "TAKAHASHIKUN" || s == "Takahashikun" || s == "takahashikun"){
            res++;
        }
    }
    cout << res << endl;
}
