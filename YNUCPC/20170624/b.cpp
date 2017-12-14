#include <iostream>
#include <vector>

int N,M;
std::vector<int> L;

void solve(){
    bool f;
    std::vector<char> vc;
    for(int S=0; S<(1<<M); ++S){
        std::cout << S << std::endl;
        vc.resize(0);
        int s = 0, h = 0;
        f = true;
        for(int k=0; k<M; ++k){
            vc.push_back( (char)( ((S>>k)&1) + '0' ) );
            if(((S>>k)&1)>0) s++;
        }
        if(s != L[0]){
            continue;
        }
        for(int i=1; i<N&&f; ++i){
            if(vc[h++] == '1') s--;
            if(L[i] == s) vc.push_back('0');
            else if(s+1 == L[i]){
                vc.push_back('1');
                s++;
            }else{
                f = false;
            }
        }
        if(f){
            break;
        }
    }

    if(f){
        int l = vc.size();
        for(int i=0; i<l; ++i){
            std::cout << vc[i];
        }
        std::cout << std::endl;
    }else{
        std::cout << "Goofy" << std::endl;
    }
}

int main(void){
    while(std::cin >> N >> M){
        if(N == 0 && M == 0) break;
        L.resize(N);
        for(int i=0; i<N; ++i){
            std::cin >> L[i];
        }
        solve();
    }
}
