#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

string S;

int memo[100000][100000] = {-1};

int dfs(int i, int x){

    if(memo[i][x] != -1){
        return memo[i][x];
    }

    if(i >= S.length()){
        return memo[i][x] = ((x == 0) ? 0 : INT_MIN);
    }

    if(S[i] == 'M'){
        int a = dfs(i+1, x+1);
        int b = dfs(i+1, x-1);
        return memo[i][x] = max(a,b);
    }else if(S[i] == '+'){
        int a = dfs(i+1, x);
        return memo[i][x] = ((a != INT_MIN) ? x + a : INT_MIN);
    }else{
        int a = dfs(i+1, x);
        return memo[i][x] = ((a != INT_MIN) ? (-1)*x + a : INT_MIN);
    }
}

int main(void){
    cin >> S;

    cout << dfs(0, 0) << endl;
}
