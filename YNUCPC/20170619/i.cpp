#include<iostream>
#include<algorithm>
int a[32],n;

void dfs(int i,int remain, int rank){
    if(remain == 0){
        a[i]=remain;
        for(int j=0;j<=i;j++){
            if(a[j] > 0){
                if(j > 0){
                    std::cout<<" ";
                }
                std::cout<<a[j];
            }
        }
        std::cout<<std::endl;
        return;
    }

    for(int j=std::min(remain,rank);j>=1;j--){
        a[i]=j;
        dfs(i+1,remain-j,a[i]);
    }
    return;
}
int main(){
    while(std::cin >> n && n != 0){
        dfs(0,n,n);
    }
}
