#include <bits/stdc++.h>
using namespace std;

vector<int> twosum(int i, int target, vector<vector<int>>&arr){
    int l = i+1;
    int r = arr.size() -1;
    while(l < r){
        if(arr[l][0]+arr[r][0] == target){
            return{l,r};
        }else if(arr[l][0]+arr[r][0] < target){
            l++;
        }else{
            r--;
        }
    }

    return {-1,-1};
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t;
    cin >> n >> t;

    vector<vector<int>> arr(n,vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> arr[i][0];
        arr[i][1] = i;
    }

    if(n <= 3){
        cout << "IMPOSSIBLE";
        return 0;
    }
    sort(arr.begin(),arr.end());

    for(int i = 0; i < n-3; i++){
        for(int j = i+1; j < n-2;j++){
            vector<int> curr = twosum(j,t - arr[i][0] - arr[j][0], arr);
            if(curr[0] != -1){
                cout << arr[i][1] +1  << ' ' << arr[curr[0]][1] +1 << ' ' << arr[curr[1]][1] +1 << ' ' << arr[j][1] + 1;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
}