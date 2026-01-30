#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> intervals(n,vector<int>(2,0));
    for(int i = 0; i < n; i++){
        cin >> intervals[i][1] >> intervals[i][0];
    }
    sort(intervals.begin(),intervals.end());
    int ans = 0;
    int nps = 0;
    for(auto it:intervals){
        if(it[1] >= nps){
            ans++;
            nps = it[0];
        }
    }

    cout << ans;


}