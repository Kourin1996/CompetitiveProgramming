#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> A[100001];

int main(){
    std::cin >> N;
    int max = 0;
    for(int i=0; i<N; ++i){
        int a;
        std::cin >> a;
        A[a].push_back(i);
        max = std::max(max,a);
    }

    int ans = 1, p = -1;
    for (int i = 1; i <= max; i++) {
		if (A[i].empty()) continue;
        int itr = upper_bound(A[i].begin(), A[i].end(), p) - A[i].begin();
        
		if (itr == 0) {
			p = *(A[i].end()-1);
			continue;
        }
		p = A[i][itr - 1];
		if (p != 0 || i != max){
            ans++;
        }
	}
	std::cout << ans << std::endl;
}