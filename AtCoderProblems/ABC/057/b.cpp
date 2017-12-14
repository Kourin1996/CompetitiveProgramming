#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

int N, M;
vector< pair<int,int> > student;
vector< pair<int,int> > point;

int main(void){
    cin >> N >> M;

    student.resize(N);
    for(int i=0; i<N; ++i){
        cin >> student[i].first >> student[i].second;
    }

    point.resize(M);
    for(int i=0; i<M; ++i){
        cin >> point[i].first >> point[i].second;
    }

    pair<int,int> ans;
    for(int i=0; i<N; ++i){
        ans.first = 0;
        ans.second = INT_MAX;

        for(int j=0; j<M; ++j){
            int dis = abs(student[i].first-point[j].first) + abs(student[i].second-point[j].second);
            if(ans.second > dis){
                ans.first = j;
                ans.second = dis;
            }
        }
        cout << ans.first + 1 << endl;
    }
}
