#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n,vector<int>(2,0));
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    sort(arr.begin(),arr.end());

    long long ans = 0;
    long long time = 0;
    for(auto it:arr){
        ans += (it[1] - time - it[0]);
        time += it[0];
    }

    cout << ans;

}